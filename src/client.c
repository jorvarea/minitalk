/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 20:16:04 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

int	main(int argc, char **argv)
{
	t_packet packet;
	int	server_pid;

	if (argc != 3)
	{
		ft_printf("Error: Invalid argument count\n");
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Error: Invalid server PID\n");
		exit(1);
	}
	packet_message(argv[2], &packet);
	send_packet(&packet, server_pid, 1000);
	return (0);
}
