/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:08:58 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/09 03:19:40 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

t_flags	init_flags(void);
t_flags	parse_flags(const char **str);
void	ft_printpad(char pad_char, int pad_len, int *len);
void	ft_printnbr_flags(int nb, t_flags flags, int total_len, char *prefix, int *len);
void	ft_printchar(char c, t_flags flags, int bl_mayus, int *len);	
void	ft_printstr(char *str, t_flags flags, int bl_mayus, int *len);
void	ft_printnbr(int nb, t_flags flags, int *len);
void	ft_printnbr_hex(unsigned int nb, t_flags flags, int bl_mayus, int *len);
void	ft_printpointer(void *ptr, t_flags flags, int *len);
int		ft_printf(char const *str, ...);

#endif
