/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:30:31 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 21:40:33 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_field(int field, int field_size, int server_pid,
		int signal_interval)
{
	int	field_bits;
	int	bits_to_move;
	int	i;

	field_bits = 8 * field_size;
	i = 0;
	while (i < field_bits && g_byte.stop_signal == false)
	{
		bits_to_move = field_bits - 1 - i;
		if (((field >> bits_to_move) & 1) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(signal_interval);
		i++;
	}
}

void	send_packet(t_packet *packet, int server_pid, int signal_interval)
{
	unsigned int	i;

	send_field(packet->payload_length, PAYLOAD_LENGTH_BYTES, server_pid,
		signal_interval);
	send_field(packet->check_sum, CHECK_SUM_BYTES, server_pid, signal_interval);
	i = 0;
	while (i < packet->payload_length && g_byte.stop_signal == false)
	{
		send_field(packet->data[i], 1, server_pid, signal_interval);
		i++;
	}
}
