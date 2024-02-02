/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:17:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/02 22:16:39 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "unistd.h"

void	ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putstr_fd(char *str, int fd);
void    ft_revstr(char *str);
int     ft_strlen(char *str);
void    ft_swap(char *a, char *b);

#endif