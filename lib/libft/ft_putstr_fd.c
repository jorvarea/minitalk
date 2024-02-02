/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:04:01 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/02 22:16:07 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void ft_putstr_fd(char *str, int fd)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}
