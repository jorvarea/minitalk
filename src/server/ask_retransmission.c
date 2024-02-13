/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_retransmission.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:38:44 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 21:35:08 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ask_retransmission(int pid)
{
	kill(pid, SIGUSR2);
	usleep(RESPONSE_SIGNAL_INTERVAL);
	kill(pid, SIGUSR1);
	usleep(RESPONSE_SIGNAL_INTERVAL);
}
