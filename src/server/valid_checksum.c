/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checksum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:27:16 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 02:54:04 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

bool	valid_checksum(t_packet *packet)
{
	unsigned int	checksum;

	checksum = calculate_checksum(packet);
	return (checksum == packet->check_sum);
}
