/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin2dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:04:53 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/02 22:25:52 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int	bin2dec(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i])
	{
		num = num * 2 + str[i] - '0';
		i++;
	}
	return (num);
}
