/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:39:45 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 18:47:44 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_ack(int pid)
{
	kill(pid, SIGUSR1);
	usleep(100);
	kill(pid, SIGUSR1);
	usleep(100);
}
