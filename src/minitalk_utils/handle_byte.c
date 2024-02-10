/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:25:49 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 20:22:53 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

static void read_checksum(unsigned char byte, t_packet *packet, t_server_state *state, int *field_bytes_read)
{
    if (*field_bytes_read == 0)
    {
        packet->check_sum = byte;
        packet->check_sum = packet->check_sum << 8;
    }
    else if (*field_bytes_read == 1)
        packet->check_sum += byte;
    (*field_bytes_read)++;
    if (*field_bytes_read == 2)
    {
        (*state)++;
        *field_bytes_read = 0;
    }
}

static void read_payload_length(unsigned char byte, t_packet *packet, t_server_state *state, int *field_bytes_read)
{
    if (*field_bytes_read == 0)
    {
        packet->payload_length = byte;
        packet->payload_length = packet->payload_length << 8;
    }
    else if (*field_bytes_read == 1)
        packet->payload_length += byte;
    (*field_bytes_read)++;
    if (*field_bytes_read == 2)
    {
        (*state)++;
        *field_bytes_read = 0;
    }
}

void handle_byte(unsigned char byte, t_packet *packet, t_server_state *state, int *field_bytes_read)
{
    if (*state == WAITING_PACKET)
        *state = READING_PAYLOAD_LENGTH;
    if (*state == READING_PAYLOAD_LENGTH)
        read_payload_length(byte, packet, state, field_bytes_read);
    else if (*state == READING_CHECKSUM)
        read_checksum(byte, packet, state, field_bytes_read);
    else if (*state == READING_DATA)
    {
        if (packet->data == NULL)
            packet->data = malloc(packet->payload_length * sizeof(char));
        packet->data[*field_bytes_read] = byte;
        (*field_bytes_read)++;
        if (*field_bytes_read == packet->payload_length)
        {
            *state = PACKET_COMPLETE;
            *field_bytes_read = 0;
        }
    }
}
