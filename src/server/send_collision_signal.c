/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_collision_signal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:59:38 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 21:34:59 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_collision_signal(int pid)
{
	kill(pid, SIGUSR1);
	usleep(RESPONSE_SIGNAL_INTERVAL);
	kill(pid, SIGUSR2);
	usleep(RESPONSE_SIGNAL_INTERVAL);
}
