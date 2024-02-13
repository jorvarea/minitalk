/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_timeout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:01:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 19:32:03 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_timeout(t_server_state *state, t_packet *packet,
		unsigned int *field_bytes_read)
{
	ft_printf("\033[0;31m");
	ft_printf("\nTimeout. Asking for retransmission...\n");
	ft_printf("\033[0m");
	*state = WAITING_PACKET;
	*field_bytes_read = 0;
	free(packet->data);
	packet->data = NULL;
	ask_retransmission(g_byte.sender_pid);
	reset_byte();
	g_byte.sender_pid = 0;
}
