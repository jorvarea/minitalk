/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_server_pid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:14:44 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 16:31:54 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	print_server_pid(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("SERVER'S PROCESS ID: %d\n", server_pid);
}
