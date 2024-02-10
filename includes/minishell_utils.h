/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:05:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/10 16:12:14 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS_H
# define MINISHELL_UTILS_H

# include <unistd.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct      s_packet
{
    int                     source_pid;
    int                     payload_length;
    int                     check_sum;
    char                    *data;
}                   t_packet;

typedef struct      s_byte
{
    volatile unsigned char  byte;
    volatile sig_atomic_t   bits_written;
}                   t_byte;

void    print_server_pid(void);
void	show_banner(void);

#endif