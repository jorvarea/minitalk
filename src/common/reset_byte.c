/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_byte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:49:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 17:32:24 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	reset_byte(void)
{
	g_byte.sender_pid = 0;
	g_byte.byte = 0;
	g_byte.bits_written = 0;
}