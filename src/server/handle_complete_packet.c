/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_complete_packet.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:26:36 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 21:20:40 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_complete_packet(t_server_state *state, t_packet *packet,
		unsigned int *field_bytes_read, t_timer *timer)
{
	if (valid_checksum(packet))
	{
		print_message(packet);
		send_ack(g_byte.sender_pid);
	}
	else
	{
		timer->timeout *= 2;
		ft_printf("\033[0;31m");
		ft_printf("\nInvalid checksum. Asking for retransmission. Current timeout: %d us\n", timer->timeout);
		ft_printf("\033[0m");
		ask_retransmission(g_byte.sender_pid);
	}
	reset_state(state, packet, field_bytes_read);
}
