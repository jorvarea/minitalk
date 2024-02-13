/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_collision_signal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:59:38 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 17:59:49 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_collision_signal(int pid)
{
	kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR1);
	usleep(100);
}
