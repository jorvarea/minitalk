/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_timeout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:01:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 14:28:57 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	handle_timeout(t_packet *packet, int server_pid, int *signal_interval,
		t_timer *timer)
{
	ft_printf("\033[0;31m");
	ft_printf("Timeout. Current signal interval: %d us. ", *signal_interval);
	ft_printf("Retransmitting...\n");
	ft_printf("\033[0m");
	*signal_interval *= 2;
	send_packet(packet, server_pid, *signal_interval);
	timer->time = 0;
}
