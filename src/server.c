/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 19:29:49 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

t_byte g_byte;

void signal_handler(int sig_num)
{
    if (sig_num == SIGUSR2)
        g_byte.byte += (1 << (7 - g_byte.bits_written));
    g_byte.bits_written++;
}

void initialize_server(t_server_state *state, int *field_bytes_read)
{
    show_banner();
    print_server_pid();
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    *state = WAITING_PACKET;
    *field_bytes_read = 0;
    ft_printf("\nReceived messages: ");
}

int main(void)
{
    t_server_state state;
    t_packet packet;
    int field_bytes_read;
    
    initialize_server(&state, &field_bytes_read);
    while (true)
    {
        if (g_byte.bits_written == 8)
        {
            handle_byte(g_byte.byte, &packet, &state, &field_bytes_read);
            g_byte.byte = 0;
            g_byte.bits_written = 0;
        }
        if (state == PACKET_COMPLETE && valid_checksum(&packet))
            print_message(packet);
        else if (state == PACKET_COMPLETE)
            ft_printf("Invalid checksum. Asking for retransmission...\n");
        pause();
    }
    return (0);
}
