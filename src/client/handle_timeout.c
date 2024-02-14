/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_timeout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:01:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 21:49:56 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_until_stop_signal(int server_pid, int signal_interval)
{
	int	new_signal_interval;

	new_signal_interval = signal_interval * SIGNAL_INTERVAL_PADDING_FACTOR;
	while (g_byte.stop_signal == 0)
	{
		kill(server_pid, SIGUSR1);
		usleep(new_signal_interval);
	}
}

void	handle_timeout(t_packet *packet, int server_pid, int *signal_interval,
		t_timer *timer)
{
	ft_printf("\033[0;31m");
	ft_printf("Timeout. Waiting for synchronization...\n");
	send_until_stop_signal(server_pid, *signal_interval);
	g_byte.stop_signal = 0;
	reset_byte();
	*signal_interval *= 2;
	ft_printf("Current signal interval: %d us. ", *signal_interval);
	ft_printf("Retransmitting...\n");
	ft_printf("\033[0m");
	send_packet(packet, server_pid, *signal_interval);
	timer->time = 0;
}
