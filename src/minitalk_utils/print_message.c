/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:32:19 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 19:33:45 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	print_message(t_packet *packet)
{
	int	i;

	i = 0;
	while (i < packet->payload_length)
		ft_printf("%c", packet->data[i++]);
}
