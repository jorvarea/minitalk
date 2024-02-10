/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checksum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:27:16 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 19:28:23 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

bool valid_checksum(t_packet *packet)
{
    int checksum;

    checksum = calculate_checksum(packet);
    return (checksum == packet->check_sum);
}
