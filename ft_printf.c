/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:02:27 by alejhern          #+#    #+#             */
/*   Updated: 2024/08/14 17:31:56 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int 	type_var(char c, va_list element)
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
}

static int	ft_printer(char const *str, va_list element)
{
	int len;
	int aux;

	len = 0;
	while(*str)
	{
		if (*str == '%') 
		{
			str++;
			if (*str == '%')
				aux = ft_printchar('%');
			else
				aux = type_var(*str, element);
			if (aux == -1)
				return (-1);
			len += aux;
		}
		else
		{
			if(ft_printchar(*str) != 1)
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

int main()
{
	char *str = "Pointer Test";
	int	len;
    
	printf("Pointer: %p\n", str);
	len = ft_printf("Pointer: %p\n", str);
	
    ft_printf("Length: %d\n", len);

	ft_printf("%u\n", -99);
	printf("%u", -99);
	return(0);
}