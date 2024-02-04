/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/04 18:48:34 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

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
        usleep(10000);
		kill(server_pid, SIGUSR2);
        usleep(10000);
		kill(server_pid, SIGUSR1);
        usleep(10000);
		kill(server_pid, SIGUSR1);
        usleep(10000);
		kill(server_pid, SIGUSR1);
        usleep(10000);
		kill(server_pid, SIGUSR1);
        usleep(10000);
		kill(server_pid, SIGUSR1);
        usleep(10000);
        kill(server_pid, SIGUSR2);
        usleep(10000);
		i++;
	}
	return (0);
}
