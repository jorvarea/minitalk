/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_server_response.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:39:33 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 16:04:39 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	handle_collision(t_packet *packet, int server_pid,
		int *signal_interval)
{
	ft_printf("\033[0;33m");
	ft_printf("Collision detected. Sleeping...\n");
	usleep(COLLISION_DELAY);
	ft_printf("Retrying...\n");
	ft_printf("\033[0m");
	g_byte.stop_signal = false;
	send_packet(packet, server_pid, *signal_interval);
}

static void	handle_retransmission(t_packet *packet, int server_pid,
		int *signal_interval)
{
	*signal_interval *= 2;
	ft_printf("\033[0;33m");
	ft_printf("Retransmission signal received. ");
	ft_printf("Current signal interval %d us. ", *signal_interval);
	ft_printf("Retransmitting...\n");
	ft_printf("\033[0m");
	g_byte.stop_signal = false;
	send_packet(packet, server_pid, *signal_interval);
}

static void	handle_success(void)
{
	ft_printf("\033[0;32m");
	ft_printf("Message received successfully\n");
	ft_printf("\033[0m");
	exit(0);
}

void	handle_server_response(t_packet *packet, int server_pid,
		int *signal_interval, t_timer *timer)
{
	if (g_byte.byte == ACK)
		handle_success();
	else if (g_byte.byte == ASKING_RETRANSMISSION)
		handle_retransmission(packet, server_pid, signal_interval);
	else if (g_byte.byte == COLLISION_DETECTED)
		handle_collision(packet, server_pid, signal_interval);
	reset_byte();
	timer->time = 0;
}
