/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:05:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/02 22:21:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS_H
# define MINISHELL_UTILS_H

# include "libft.h"

typedef enum    t_codification
{
    ASCII,
    UNICODE,
}               e_codification;

typedef struct  s_packet
{
    e_codification code;
    int len;
    int check_sum;
    char *data;
}               t_packet;

int     bin2dec(char *str);
char    *dec2bin(int x);

#endif