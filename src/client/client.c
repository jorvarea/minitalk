/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 14:18:06 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_byte		g_byte;

static void	signal_handler(int sig_num, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	g_byte.stop_signal = true;
	if (sig_num == SIGUSR2)
		g_byte.byte += (1 << g_byte.bits_written);
	g_byte.bits_written++;
}

void	initialize_client(int *signal_interval, t_timer *timer)
{
	timer->time = 0;
	timer->timeout = RESPONSE_SIGNAL_INTERVAL * 3;
	*signal_interval = INITIAL_SIGNAL_INTERVAL;
}

int	main(int argc, char **argv)
{
	t_packet			packet;
	int					signal_interval;
	int					server_pid;
	struct sigaction	sig_action;
	t_timer				timer;

	handle_input(argc, argv, &server_pid, &packet);
	initialize_client(&signal_interval, &timer);
	initialize_sigaction(&sig_action, signal_handler);
	send_packet(&packet, server_pid, signal_interval);
	ft_printf("Initial signal interval: %d us\n", signal_interval);
	while (true)
	{
		if (g_byte.bits_written == 2)
			handle_server_response(&packet, server_pid, &signal_interval,
				&timer);
		if (timer.time * SLEEP_TIME > timer.timeout)
			handle_timeout(&packet, server_pid, &signal_interval, &timer);
		timer.time++;
		usleep(SLEEP_TIME);
	}
	return (0);
}
