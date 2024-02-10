/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:05:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 16:32:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_H
# define MINITALK_UTILS_H

# include <unistd.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct      s_packet
{
    int                     payload_length;
    int                     check_sum;
    char                    *data;
}                   t_packet;

typedef struct      s_byte
{
    volatile unsigned char  byte;
    volatile sig_atomic_t   bits_written;
}                   t_byte;

// Server
void    print_server_pid(void);
void	show_banner(void);

// Client
void    packet_message(char *message, t_packet *packet);

#endif