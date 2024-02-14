/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:01:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 14:18:33 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "common.h"

# define MAX_PAYLOAD 65535
# define COLLISION_DELAY 100000
# define SLEEP_TIME 100
# define INITIAL_SIGNAL_INTERVAL 15

typedef enum e_server_response
{
	ACK = 0,
	ASKING_RETRANSMISSION = 1,
	COLLISION_DETECTED = 2,
}							t_server_response;

typedef struct s_byte
{
	volatile bool			stop_signal;
	volatile unsigned char	byte;
	volatile int			bits_written;
}							t_byte;

extern t_byte				g_byte;

void						handle_input(int argc, char **argv, int *server_pid,
								t_packet *packet);
void						packet_message(char *message, t_packet *packet);
void						send_packet(t_packet *packet, int server_pid,
								int signal_interval);
void						handle_server_response(t_packet *packet,
								int server_pid, int *signal_interval,
								t_timer *timer);
void						handle_timeout(t_packet *packet, int server_pid,
								int *signal_interval, t_timer *timer);

#endif