/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_banner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:10:21 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/03 23:34:06 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void	show_banner(void)
{
    ft_printf("\n\n");
    ft_printf("\033[0;35m");
	ft_printf("##     ## #### ##    ## #### ########    ###    ##       ");
    ft_printf("##    ##\n");
    ft_printf("\033[0;34m");
	ft_printf("###   ###  ##  ###   ##  ##     ##      ## ##   ##       ");
    ft_printf("##   ## \n");
	ft_printf("#### ####  ##  ####  ##  ##     ##     ##   ##  ##       ");
    ft_printf("##  ##  \n");
	ft_printf("## ### ##  ##  ## ## ##  ##     ##    ##     ## ##       ");
    ft_printf("#####   \n");
	ft_printf("##     ##  ##  ##  ####  ##     ##    ######### ##       ");
    ft_printf("##  ##  \n");
	ft_printf("##     ##  ##  ##   ###  ##     ##    ##     ## ##       ");
    ft_printf("##   ## \n");
    ft_printf("\033[0;35m");
	ft_printf("##     ## #### ##    ## ####    ##    ##     ## ######## ");
    ft_printf("##    ##\n");
    ft_printf("\e[0m");
    ft_printf("\n\n");
}