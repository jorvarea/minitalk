/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:05:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/03 21:55:11 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS_H
# define MINISHELL_UTILS_H

# include "libft.h"

typedef enum    e_codification
{
    ASCII = 0,
    UNICODE = 1,
}               t_codification;

typedef enum    e_flag
{
    DATA = 0,
    ACK = 1,
    FIN = 2,
}               t_flag;

typedef struct  s_packet
{
    int source_pid;
    t_codification code;
    t_flag flag;
    int seq_num;
    int ack_num;
    int payload_len;
    int check_sum;
    unsigned char *data;
}               t_packet;

int     bin2dec(char *str);
char    *dec2bin(int x);

#endif