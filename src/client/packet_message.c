/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:31:09 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 13:41:50 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	packet_message(char *message, t_packet *packet)
{
	packet->payload_length = ft_strlen(message);
	if (packet->payload_length > MAX_PAYLOAD)
	{
		ft_printf("\033[0;31m");
		ft_printf("Error: Message is too large\n");
		ft_printf("\033[0m");
		exit(1);
	}
	packet->data = message;
	packet->check_sum = calculate_checksum(packet);
}
