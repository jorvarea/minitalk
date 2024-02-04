/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:05:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/04 19:09:01 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS_H
# define MINISHELL_UTILS_H

# include <unistd.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

typedef enum    e_codification
{
    ASCII = 0,
    UNICODE = 1,
}               t_codification;

typedef struct  s_packet
{
    int source_pid;
    t_codification code;
    int payload_len;
    int check_sum;
    unsigned char *data;
}               t_packet;

typedef struct      s_byte
{
    volatile unsigned char byte;
    volatile sig_atomic_t bits_written;
}                   t_byte;

void    print_server_pid(void);
void	show_banner(void);

#endif