/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout_conditions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:23:48 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 14:24:08 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

bool	timeout_conditions(t_server_state state, unsigned int payload_length,
		t_timer *timer)
{
	bool	is_timeout;

	is_timeout = false;
	if (state == READING_PAYLOAD_LENGTH && timer->time > (2 * timer->timeout))
		is_timeout = true;
	else if (state == READING_DATA && timer->time > (timer->timeout
			* payload_length))
		is_timeout = true;
	return (is_timeout);
}
