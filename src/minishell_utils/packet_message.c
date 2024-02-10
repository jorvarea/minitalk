/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:31:09 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 16:09:03 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

static int unicode_lenght(unsigned char *str)
{
    int i;

    i = 0;
    while(!ft_isascii(str[i]))
        i++;
    return (i);
}

static void packet_unicode(unsigned char **current_char, t_packet *packet)
{
    size_t data_size;
    int i;

    data_size = unicode_lenght(*current_char);
    packet->data = malloc((data_size + 1) * sizeof(unsigned char));
    i = 0;
    while (i < data_size)
    {
        packet->data[i] = **current_char;
        (*current_char)++;
        i++;
    }
    packet->data[i] = '\0';
    packet->code = UNICODE;
    packet->payload_length = data_size;
    packet->check_sum = calculate_checksum(packet);
}

static int ascii_lenght(unsigned char *str)
{
    int i;

    i = 0;
    while(ft_isascii(str[i]))
        i++;
    return (i);
}

static void packet_ascii(unsigned char **current_char, t_packet *packet)
{
    size_t data_size;
    int i;

    data_size = ascii_lenght(*current_char);
    packet->data = malloc((data_size + 1) * sizeof(unsigned char));
    i = 0;
    while (i < data_size)
    {
        packet->data[i] = **current_char;
        (*current_char)++;
        i++;
    }
    packet->data[i] = '\0';
    packet->payload_length = data_size;
    packet->check_sum = calculate_checksum(packet);
}

void packet_message(unsigned char *message, t_packet **packet_array, int *packet_count)
{
    char *current_char;
    
    *packet_count = 0;
    current_char = message;
    while (current_char != NULL)
    {
        packet_array[*packet_count] = malloc(sizeof(t_packet));
        if (ft_isascii(current_char))
            packet_ascii(&current_char, packet_array[*packet_count]);
        else
            packet_unicode(&current_char, packet_array[*packet_count]);
        (*packet_count)++;
    }
}
