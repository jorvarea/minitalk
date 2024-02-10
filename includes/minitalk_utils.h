/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:05:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 18:15:09 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_H
# define MINITALK_UTILS_H

# include <unistd.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

# define PAYLOAD_LENGTH_BYTES   2
# define CHECK_SUM_BYTES        2

typedef struct      s_packet
{
    int                     payload_length;
    int                     check_sum;
    char                    *data;
}                   t_packet;

typedef struct      s_byte
{
    volatile unsigned char  byte;
    volatile int            bits_written;
}                   t_byte;

typedef enum        e_server_state
{
    WAITING_PACKET  = 0,
    READING_HEADER  = 1,
    READING_DATA    = 2,
}                   t_server_state;

// Common
int	calculate_checksum(t_packet *packet);

// Server
void    print_server_pid(void);
void	show_banner(void);

// Client
void    packet_message(char *message, t_packet *packet);
void	send_packet(t_packet *packet, int server_pid, int signal_interval);

#endif