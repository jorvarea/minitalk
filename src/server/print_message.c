/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:32:19 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 02:52:17 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print_message(t_packet *packet)
{
	unsigned int	i;

	i = 0;
	while (i < packet->payload_length)
		ft_printf("%c", packet->data[i++]);
}
