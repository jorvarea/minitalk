/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 02:53:48 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_byte	g_byte;

void	signal_handler(int sig_num)
{
	if (sig_num == SIGUSR2)
		g_byte.byte += (1 << (7 - g_byte.bits_written));
	g_byte.bits_written++;
}

bool	timeout_conditions(t_server_state state, unsigned int payload_length,
		unsigned int timer, unsigned int timeout)
{
	bool	is_timeout;

	is_timeout = false;
	if (state == READING_PAYLOAD_LENGTH && timer > (2 * timeout))
		is_timeout = true;
	else if (state == READING_DATA && timer > (timeout * payload_length))
		is_timeout = true;
	return (is_timeout);
}

void	initialize_server(t_server_state *state, t_packet *packet,
		unsigned int *field_bytes_read, unsigned int *timeout)
{
	show_banner();
	print_server_pid();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	*state = WAITING_PACKET;
	packet->data = NULL;
	*field_bytes_read = 0;
	*timeout = 800;
	ft_printf("\nReceived messages: ");
}

int	main(void)
{
	t_server_state	state;
	t_packet		packet;
	unsigned int	field_bytes_read;
	unsigned int	timeout;
	unsigned int	timer;

	initialize_server(&state, &packet, &field_bytes_read, &timeout);
	while (true)
	{
		if (g_byte.bits_written >= 8)
		{
			handle_byte(g_byte.byte, &packet, &state, &field_bytes_read);
			g_byte.byte = 0;
			g_byte.bits_written = 0;
		}
		if (state == PACKET_COMPLETE)
			handle_complete_packet(&state, &packet, &field_bytes_read);
		if (state == WAITING_PACKET || state == READING_CHECKSUM)
			timer = 0;
		if (timeout_conditions(state, packet.payload_length, timer, timeout))
			handle_timeout(&state, &packet, &field_bytes_read);
		timer++;
		usleep(1);
	}
	return (0);
}
