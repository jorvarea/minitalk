/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_retransmission.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:38:44 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 17:39:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ask_retransmission(int pid)
{
	kill(pid, SIGUSR1);
	usleep(100);
	kill(pid, SIGUSR2);
	usleep(100);
}
