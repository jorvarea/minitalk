/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_timeout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:01:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 21:07:06 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	handle_timeout(t_packet *packet, int server_pid, int *signal_interval,
		t_timer *timer)
{
	*signal_interval *= 2;
	ft_printf("\033[0;31m");
	ft_printf("Timeout. Current signal interval: %d us. ", *signal_interval);
	ft_printf("Retransmitting...\n");
	ft_printf("\033[0m");
	send_packet(packet, server_pid, *signal_interval);
	timer->time = 0;
}
