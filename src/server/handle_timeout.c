/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_timeout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:01:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/12 22:13:23 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void handle_timeout(t_server_state *state, t_packet *packet, int *field_bytes_read)
{
    ft_printf("\033[0;31m");
    ft_printf("\nTimeout. Asking for retransmission...\n");
    ft_printf("\033[0m");
    *state = WAITING_PACKET;
    g_byte.byte = 0;
    g_byte.bits_written = 0;
    *field_bytes_read = 0;
    free(packet->data);
	packet->data = NULL;
}
