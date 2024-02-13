/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 17:37:34 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_byte	g_byte;

void send_collision_signal(int pid)
{
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR1);
	usleep(100);
}

void	signal_handler(int sig_num, siginfo_t *info, void *context)
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

void	initialize_sigaction(struct sigaction *sig_action)
{
	ft_memset(sig_action, 0, sizeof(struct sigaction));
	sig_action->sa_flags = SA_RESTART | SA_SIGINFO;
	sig_action->sa_sigaction = signal_handler;
	sigaction(SIGUSR1, sig_action, NULL);
	sigaction(SIGUSR2, sig_action, NULL);
}

int	main(void)
{
	t_server_state		state;
	t_packet			packet;
	unsigned int		field_bytes_read;
	t_timer				timer;
	struct sigaction	sig_action;

	initialize_server(&state, &packet, &field_bytes_read, &timer.timeout);
	initialize_sigaction(&sig_action);
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
