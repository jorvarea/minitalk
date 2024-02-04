/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/04 19:06:28 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

t_byte g_byte;

void signal_handler(int sig_num)
{
    if (sig_num == SIGUSR2)
        g_byte.byte += (1 << (7 - g_byte.bits_written));
    g_byte.bits_written++;
}

int main(void)
{
    show_banner();
    print_server_pid();
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (true)
    {
        if (g_byte.bits_written == 8)
        {
            ft_printf("%c", g_byte.byte);
            g_byte.byte = 0;
            g_byte.bits_written = 0;
        }
        pause();
    }
    return (0);
}
