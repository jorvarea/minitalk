/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_checksum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:25:40 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 15:27:28 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int calculate_checksum(t_packet *packet)
{
    int sum;
    int i;

    sum = 0;
    sum += packet->code;
    sum += packet->payload_length;
    i = 0;
    while (packet->data[i])
        sum += packet->data[i++];
    return (sum);
}
