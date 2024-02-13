/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:01:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 20:11:07 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "common.h"

typedef enum e_server_response
{
    ACK = 0,
    ASKING_RETRANSMISSION = 1,
    COLLISION_DETECTED = 2,
}           t_server_response;

typedef struct s_byte
{
	volatile int			stop_signal;
	volatile unsigned char	byte;
	volatile int			bits_written;
}							t_byte;

void	packet_message(char *message, t_packet *packet);
void	send_packet(t_packet *packet, int server_pid, int signal_interval);

#endif