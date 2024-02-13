/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 02:33:07 by jorvarea         ###   ########.fr       */
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

void	initialize_server(t_server_state *state, t_packet *packet,
		int *field_bytes_read)
{
	show_banner();
	print_server_pid();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	*state = WAITING_PACKET;
	packet->data = NULL;
	*field_bytes_read = 0;
	ft_printf("\nReceived messages: ");
}

int	main(void)
{
	t_server_state			state;
	t_packet				packet;
	int						field_bytes_read;
	unsigned int			timeout;
	unsigned long long int 	timer;

	initialize_server(&state, &packet, &field_bytes_read);
	timeout = 800;
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
		if ((state == READING_PAYLOAD_LENGTH && timer > (2 * timeout)) || (state == READING_DATA && timer > (timeout * packet.payload_length)))
			handle_timeout(&state, &packet, &field_bytes_read);
		timer++;
		usleep(1);
	}
	return (0);
}
