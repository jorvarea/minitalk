/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:34:53 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/14 13:40:23 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void handle_input(int argc, char **argv, int *server_pid, t_packet *packet)
{
	if (argc != 3)
	{
		ft_printf("\033[0;31m");
		ft_printf("Error: Invalid argument count\n");
		ft_printf("\033[0m");
		exit(1);
	}
	*server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("\033[0;31m");
		ft_printf("Error: Invalid server PID\n");
		ft_printf("\033[0m");
		exit(1);
	}
    packet_message(argv[2], packet);
}
