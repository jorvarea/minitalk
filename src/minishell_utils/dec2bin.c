/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec2bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:53:33 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/03 22:32:51 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

char	*dec2bin(int x)
{
	char	*str;
	int		i;

	str = malloc((32 + 1) * sizeof(char));
	if (!str)
	{
		ft_putstr_fd("Failed to allocate memory\n", 1);
		exit(1);
	}
	i = 0;
	if (x == 0)
	{
		while (i < 32)
			str[i++] = '0';
	}
	else
	{
		while (x)
		{
			str[i] = x % 2 + '0';
			x /= 2;
			i++;
		}
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
