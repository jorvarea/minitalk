/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:01:21 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 00:30:11 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>

# define PAYLOAD_LENGTH_BYTES 2
# define CHECK_SUM_BYTES 2

typedef struct s_packet
{
	unsigned int			payload_length;
	unsigned int			check_sum;
	char					*data;
}							t_packet;

int		calculate_checksum(t_packet *packet);

#endif