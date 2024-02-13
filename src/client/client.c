/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:07:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 21:30:47 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_byte		g_byte;

static void	signal_handler(int sig_num, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	g_byte.stop_signal = true;
	if (sig_num == SIGUSR2)
		g_byte.byte += (1 << g_byte.bits_written);
	g_byte.bits_written++;
}

void	handle_server_response(t_packet *packet, int server_pid,
		int *signal_interval)
{
	if (g_byte.byte == ACK)
	{
		ft_printf("\033[0;32m");
		ft_printf("Message received successfully\n");
		ft_printf("\033[0m");
		exit(0);
	}
	else if (g_byte.byte == ASKING_RETRANSMISSION)
	{
		ft_printf("\033[0;33m");
		ft_printf("Retransmission signal received. ");
		ft_printf("Retransmitting with %d us signal interval...\n", 
			*signal_interval);
		ft_printf("\033[0m");
		g_byte.stop_signal = false;
		*signal_interval *= 2;
		send_packet(packet, server_pid, *signal_interval);
	}
	else if (g_byte.byte == COLLISION_DETECTED)
	{
		ft_printf("\033[0;33m");
		ft_printf("Collision detected. Sleeping...\n");
		usleep(COLLISION_DELAY);
		ft_printf("Retrying...\n");
		ft_printf("\033[0m");
		g_byte.stop_signal = false;
		send_packet(packet, server_pid, *signal_interval);
	}
	reset_byte();
}

void	initialize_client(int argc, char **argv, int *server_pid,
		int *signal_interval)
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
	*signal_interval = INITIAL_SIGNAL_INTERVAL;
}

int	main(int argc, char **argv)
{
	t_packet			packet;
	int					signal_interval;
	int					server_pid;
	struct sigaction	sig_action;

	initialize_client(argc, argv, &server_pid, &signal_interval);
	initialize_sigaction(&sig_action, signal_handler);
	packet_message(argv[2], &packet);
	send_packet(&packet, server_pid, signal_interval);
	while (true)
	{
		if (g_byte.bits_written == 2)
			handle_server_response(&packet, server_pid, &signal_interval);
		pause();
	}
	return (0);
}
