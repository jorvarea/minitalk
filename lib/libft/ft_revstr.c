/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:05:16 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/02 22:10:48 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void ft_revstr(char *str)
{
    int size;
    int i;

    size = ft_strlen(str);
    i = 0;
    while (i < size / 2)
        ft_swap(&str[i], &str[size - i - 1]);
}
