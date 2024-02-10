/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_complete_packet.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:26:36 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 21:18:34 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	handle_complete_packet(t_server_state *state, t_packet *packet)
{
	if (valid_checksum(packet))
		print_message(packet);
	else
	{
		ft_printf("\033[0;31m");
		ft_printf("\nInvalid checksum. Asking for retransmission...\n");
		ft_printf("\033[0m");
	}
	*state = WAITING_PACKET;
	free(packet->data);
	packet->data = NULL;
}
