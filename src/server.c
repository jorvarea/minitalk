/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/04 14:00:07 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void signal_handler(int sig_num)
{
    if (sig_num == SIGUSR1)
        ft_printf("0");
    else if (sig_num == SIGUSR2)
        ft_printf("1");
}

int main(void)
{
    show_banner();
    print_server_pid();
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (true)
        pause();
    return 0;
}
