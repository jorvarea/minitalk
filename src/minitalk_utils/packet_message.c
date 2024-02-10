/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:31:09 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 17:40:38 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"
#define MAX_PAYLOAD 65535

void packet_message(char *message, t_packet *packet)
{
    packet->payload_length = ft_strlen(message);
    if (packet->payload_length > MAX_PAYLOAD)
    {
        ft_printf("Error: Message is too large\n");
        exit(1);
    }
    packet->data = message;
    packet->check_sum = calculate_checksum(packet);
}
