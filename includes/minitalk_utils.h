/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:05:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 19:39:50 by jorvarea         ###   ########.fr       */
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
    WAITING_PACKET          = 0,
    READING_PAYLOAD_LENGTH  = 1,
    READING_CHECKSUM        = 2,
    READING_DATA            = 3,
    PACKET_COMPLETE         = 4,
}                   t_server_state;

// Server
void    print_server_pid(void);
void	show_banner(void);
void    handle_byte(unsigned char byte, t_packet *packet, t_server_state *state, int *field_bytes_read);
bool    valid_checksum(t_packet *packet);
void    print_message(t_packet *packet);

// Client
void    packet_message(char *message, t_packet *packet);
int	    calculate_checksum(t_packet *packet);
void	send_packet(t_packet *packet, int server_pid, int signal_interval);

#endif