/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 18:02:57 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_byte	g_byte;

static void	signal_handler(int sig_num, siginfo_t *info, void *context)
{
	(void)context;
	if (g_byte.sender_pid == 0)
		g_byte.sender_pid = info->si_pid;
	else if (g_byte.sender_pid != info->si_pid)
		send_collision_signal(info->si_pid);
	if (sig_num == SIGUSR2)
		g_byte.byte += (1 << (7 - g_byte.bits_written));
	g_byte.bits_written++;
}

void	initialize_server(t_server_state *state, t_packet *packet,
		unsigned int *field_bytes_read, unsigned int *timeout)
{
	show_banner();
	print_server_pid();
	*state = WAITING_PACKET;
	packet->data = NULL;
	*field_bytes_read = 0;
	*timeout = 800;
	ft_printf("\nReceived messages: ");
}

int	main(void)
{
	t_server_state		state;
	t_packet			packet;
	unsigned int		field_bytes_read;
	t_timer				timer;
	struct sigaction	sig_action;

	initialize_server(&state, &packet, &field_bytes_read, &timer.timeout);
	initialize_sigaction(&sig_action, signal_handler);
	while (true)
	{
		if (g_byte.bits_written >= 8)
			handle_byte(g_byte.byte, &packet, &state, &field_bytes_read);
		if (state == PACKET_COMPLETE)
			handle_complete_packet(&state, &packet, &field_bytes_read);
		if (state == WAITING_PACKET || state == READING_CHECKSUM)
			timer.time = 0;
		if (timeout_conditions(state, packet.payload_length, &timer))
			handle_timeout(&state, &packet, &field_bytes_read);
		timer.time++;
		usleep(1);
	}
	return (0);
}
