/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:01:21 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 14:01:45 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>

# define PAYLOAD_LENGTH_BYTES 2
# define CHECK_SUM_BYTES 2
# define RESPONSE_SIGNAL_INTERVAL 1000

typedef struct s_packet
{
	unsigned int	payload_length;
	unsigned int	check_sum;
	char			*data;
}					t_packet;

typedef struct s_timer
{
	unsigned int	time;
	unsigned int	timeout;
}					t_timer;

int					calculate_checksum(t_packet *packet);
void				reset_byte(void);
void				initialize_sigaction(struct sigaction *sig_action,
						void (*signal_handler)(int, siginfo_t *, void *));

#endif