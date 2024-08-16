/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:02:27 by alejhern          #+#    #+#             */
/*   Updated: 2024/08/16 23:33:08 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	type_var(char c, va_list element)
{
	if (c == 'c' || c == '%')
		return (ft_printchar(va_arg(element, int)));
	if (c == 's')
		return (ft_printstr(va_arg(element, char *), 0));
	if (c == 'p')
		return (ft_printpointer(va_arg(element, void *)));
	if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(element, int), 10, 0, 0));
	if (c == 'u')
		return (ft_printnbr(va_arg(element, int), 10, 1, 0));
	if (c == 'x')
		return (ft_printnbr(va_arg(element, int), 16, 0, 0));
	if (c == 'X')
		return (ft_printnbr(va_arg(element, int), 16, 0, 1));
	return (0);
}

static int	check_print_param(char c, va_list element)
{
	if (c == '%')
		return (ft_printchar('%'));
	else
		return (type_var(c, element));
}

static int	ft_printer(char const *str, va_list element)
{
	int	len;
	int	aux;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			aux = check_print_param(*str, element);
			if (aux == -1)
				return (-1);
			len += aux;
		}
		else
		{
			if (ft_printchar(*str) != 1)
				return (-1);
			len++;
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

int	main(void)
{
	char	*str;
	int		len;

	str = "Pointer Test";
	printf("Pointer: %p\n", str);
	len = ft_printf("Pointer: %p", str);
	ft_printf("\nLength: %d\n", len);
	ft_printf("%u\n", -99);
	printf("%u", -99);
	return (0);
}
