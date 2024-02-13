/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:48:06 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 19:51:20 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	reset_state(t_server_state *state, t_packet *packet,
		unsigned int *field_bytes_read)
{
	*state = WAITING_PACKET;
	*field_bytes_read = 0;
	g_byte.sender_pid = 0;
	reset_byte();
	free(packet->data);
	packet->data = NULL;
}
