/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:31:09 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 16:31:48 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void packet_message(char *message, t_packet *packet)
{
    packet->payload_length = ft_strlen(message);
    packet->data = message;
    packet->check_sum = calculate_checksum(packet);
}
