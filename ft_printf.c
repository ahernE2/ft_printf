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

int	ft_printchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int ft_printstr(char const *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (ft_printchar(*str) != 1)
			return (-1);
		len++;
		str++;
	}
	return (len);
}

 int ft_printnbr(int nb, unsigned int isunsigned)
{
	int	len;

	str = ft_itoa(nb);
	if (!str)
		return (-1);
	if (isunsigned && nb < 0)
		str++;
	len = ft_printstr(str);
	free(str);
	str = NULL;
	return (len);
}

static int 	type_var(char c, va_list element)
{
	if (c == 'c' || c == '%')
		return (ft_printchar(va_arg(element, int)));
	if (c == 's')
		return (ft_printstr(va_arg(element, char *)));
	if (c == 'p' || c == 'x')
		return (ft_printnbr_hexa(va_arg(element, int), 0));
	if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(element, int), 0));
	if (c == 'u')
		return (ft_printnbr(va_arg(element, int), 1));
	if (c == 'X')
		return (ft_printnbr_hexa(va_arg(element, int), 1))
}

static int	ft_printer(char const *str, va_list element)
{
	int len;
	int aux;

	len = 0;
	aux = 0;
	while(*str)
	{
		if (*str == '%')
		{
			str++;
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
	

int	ft_prinf(char const *str, ...)
{
	va_list	elemen;
	int		len;


