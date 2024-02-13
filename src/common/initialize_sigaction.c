/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sigaction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:54:52 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/13 17:57:26 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	initialize_sigaction(struct sigaction *sig_action,
		void (*signal_handler)(int, siginfo_t *, void *))
{
	ft_memset(sig_action, 0, sizeof(struct sigaction));
	sig_action->sa_flags = SA_RESTART | SA_SIGINFO;
	sig_action->sa_sigaction = signal_handler;
	sigaction(SIGUSR1, sig_action, NULL);
	sigaction(SIGUSR2, sig_action, NULL);
}
