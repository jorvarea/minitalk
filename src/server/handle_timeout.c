/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_timeout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:01:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 21:53:17 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_timeout(t_server_state *state, t_packet *packet,
		unsigned int *field_bytes_read, t_timer *timer)
{
	timer->timeout *= 2;
	ft_printf("\033[0;31m");
	ft_printf("\nTimeout. Asking for retransmission. ");
	ft_printf("Current timeout: %d us\n", timer->timeout);
	ft_printf("\033[0m");
	ask_retransmission(g_byte.sender_pid);
	reset_state(state, packet, field_bytes_read);
}
