/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:02:27 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/09 03:44:14 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	type_var(char c, va_list element, t_flags flags)
{
	int	len;

	len = 0;
	if (c == 'c')
		ft_printchar(va_arg(element, int), flags, 0, &len);
	if (c == 's')
		ft_printstr(va_arg(element, char *), flags, 0, &len);
	if (c == 'p')
		ft_printpointer(va_arg(element, void *), flags, &len);
	if (c == 'd' || c == 'i')
		ft_printnbr(va_arg(element, int), flags, &len);
	if (c == 'u')
		ft_printnbr(va_arg(element, unsigned int), flags, &len);
	if (c == 'x')
		ft_printnbr_hex(va_arg(element, unsigned int), flags, 0, &len);
	if (c == 'X')
		ft_printnbr_hex(va_arg(element, unsigned int), flags, 1, &len);
	if (c == '%')
		ft_printchar('%', flags, 0, &len);
	return (len);
}

static int	ft_printer(char const *str, va_list element)
{
	int		len;
	int		aux;
	t_flags	flags;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flags = parse_flags(&str);
			aux = type_var(*str, element, flags);
			if (aux == -1)
				return (-1);
			len += aux;
		}
		else
		{
			ft_printchar(*str, init_flags(), 0, &len);
			if (len == -1)
				return (-1);
		}
		str++;
	}
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	element;
	int		len;

	va_start(element, str);
	len = ft_printer(str, element);
	va_end(element);
	return (len);
}
