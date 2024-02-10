/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_checksum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:25:40 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 16:51:33 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"
#define MODULUS 65536

int	calculate_checksum(t_packet *packet)
{
	int	sum;
	int	i;

	sum = 0;
	sum += packet->payload_length;
	i = 0;
	while (packet->data[i])
		sum = (sum + (unsigned char)packet->data[i++]) % MODULUS;
	return (sum);
}
