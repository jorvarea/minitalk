/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 17:48:57 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

int	main(int argc, char **argv)
{
	t_packet packet;
	int	server_pid;

	if (argc != 3)
	{
		ft_printf("Error\n");
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	packet_message(argv[2], &packet);
	send_packet(&packet, server_pid, 1000);
	return (0);
}
