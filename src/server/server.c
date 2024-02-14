/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 13:29:13 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_byte		g_byte;

static void	signal_handler(int sig_num, siginfo_t *info, void *context)
{
	(void)context;
	if (g_byte.sender_pid == 0)
		g_byte.sender_pid = info->si_pid;
	if (info->si_pid == g_byte.sender_pid)
	{
		if (sig_num == SIGUSR2)
			g_byte.byte += (1 << (7 - g_byte.bits_written));
		g_byte.bits_written++;
	}
	else
		send_collision_signal(info->si_pid);
}

void	initialize_server(t_server_state *state, t_packet *packet,
		unsigned int *field_bytes_read)
{
	show_banner();
	print_server_pid();
	*state = WAITING_PACKET;
	packet->data = NULL;
	*field_bytes_read = 0;
	ft_printf("\nReceived messages: ");
}

int	main(void)
{
	t_server_state		state;
	t_packet			packet;
	unsigned int		field_bytes_read;
	struct sigaction	sig_action;

	initialize_server(&state, &packet, &field_bytes_read);
	initialize_sigaction(&sig_action, signal_handler);
	while (true)
	{
		if (g_byte.bits_written >= 8)
			handle_byte(g_byte.byte, &packet, &state, &field_bytes_read);
		if (state == PACKET_COMPLETE)
			handle_complete_packet(&state, &packet, &field_bytes_read);
		pause();
	}
	return (0);
}
