/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/04 14:16:24 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int main(int argc, char **argv)
{
    int server_pid;
    int i;
    
    if (argc != 2)
    {
        ft_printf("Error\n");
        exit(1);
    }
    server_pid = ft_atoi(argv[1]);
    i = 0;
    while (i < 100)
    {
        kill(server_pid, SIGUSR1);
        i++;
        usleep(10);
    }
    kill(server_pid, SIGUSR2);
    return (0);
}
