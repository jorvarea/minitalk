/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:01:26 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 18:06:00 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "common.h"

typedef enum e_server_state
{
	WAITING_PACKET = 0,
	READING_PAYLOAD_LENGTH = 1,
	READING_CHECKSUM = 2,
	READING_DATA = 3,
	PACKET_COMPLETE = 4,
}							t_server_state;

extern t_byte				g_byte;

void						print_server_pid(void);
void						show_banner(void);
void						handle_byte(unsigned char byte, t_packet *packet,
								t_server_state *state,
								unsigned int *field_bytes_read);
void						send_ack(int pid);
void						send_collision_signal(int pid);
void						ask_retransmission(int pid);
void						handle_complete_packet(t_server_state *state,
								t_packet *packet,
								unsigned int *field_bytes_read);
bool						valid_checksum(t_packet *packet);
void						print_message(t_packet *packet);
bool						timeout_conditions(t_server_state state,
								unsigned int payload_length, t_timer *timer);
void						handle_timeout(t_server_state *state,
								t_packet *packet,
								unsigned int *field_bytes_read);

#endif