/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 18:26:20 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_byte g_byte;

static void	signal_handler(int sig_num, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig_num == SIGUSR2)
		g_byte.byte += (1 << (7 - g_byte.bits_written));
	g_byte.bits_written++;
}

void initialize_client(int argc, char **argv, int *server_pid)
{
	if (argc != 3)
	{
		ft_printf("Error: Invalid argument count\n");
		exit(1);
	}
	*server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Error: Invalid server PID\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_packet			packet;
	int					server_pid;
	struct sigaction	sig_action;

	initialize_client(argc, argv, &server_pid);
	initialize_sigaction(&sig_action, signal_handler);
	packet_message(argv[2], &packet);
	send_packet(&packet, server_pid, 100);
	while (true)
	{
		if (g_byte.bits_written == 2)
		{
			if (g_byte.byte == ACK)
			{
				ft_printf("Message received successfully\n");
				exit(0);
			}
			else if (g_byte.byte == ASKING_RETRANSMISSION)
			{
				ft_printf("Retransmission signal received. Retransmitting...\n");
				send_packet(&packet, server_pid, 100);
			}
			else if (g_byte.byte == COLLISION_DETECTED)
			{
				ft_printf("Collision detected. Sleeping...\n");
				usleep(10000);
				ft_printf("Retrying...\n");
				send_packet(&packet, server_pid, 100);
			}
		}
		pause();
	}
	return (0);
}
