/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:08:58 by alejhern          #+#    #+#             */
/*   Updated: 2024/08/16 23:15:30 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printpointer(void *ptr);
int	ft_printnbr(int nb, int base, int isunsigned, int bl_mayus);
int	ft_printstr(char *str, unsigned int bl_mayus);
int	ft_printchar(char c);

#endif
