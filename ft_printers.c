/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:59:05 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/09 03:53:44 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printchar(char c, t_flags flags, int bl_mayus, int *len)
{
	if (*len == -1)
		return ;
	ft_printstr_flags(flags, 1, len);
	if (*len == -1)
		return ;
	if (bl_mayus)
		c = ft_toupper(c);
	if (write(1, &c, 1) != 1)
		*len = -1;
	(*len)++;
	ft_printstr_flags(flags, 1, len);
}

void	ft_printstr(char *str, t_flags flags, int bl_mayus, int *len)
{
	int	str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flags.dot >= 0 && flags.dot < str_len)
		str_len = flags.dot;
	ft_printstr_flags(flags, str_len, len);
	while (*str && str_len--)
		ft_printchar(*str++, init_flags(), bl_mayus, len);
	ft_printstr_flags(flags, str_len, len);
}

void	ft_printnbr(int nb, t_flags flags, int *len)
{
	char	*str;

	str = ft_itoa(nb);
	if (!str)
		*len = -1;
	if (nb >= 0 && flags.plus)
		ft_printchar('+', init_flags(), 0, len);
	else if (nb >= 0 && flags.space)
		ft_printchar(' ', init_flags(), 0, len);
	if (flags.minus && str)
	{
		ft_printstr(str, init_flags(), 0, len);
		ft_printpad(' ', flags.width - *len, len);
	}
	else
	{
		if (flags.zero && flags.width > *len)
			ft_printpad('0', flags.width - *len, len);
		else
			ft_printpad(' ', flags.width - *len, len);
		ft_printstr(str, init_flags(), 0, len);
	}
	free(str);
}

void	ft_printnbr_hex(unsigned int nb, t_flags flags, int bl_mayus, int *len)
{
	char	*str;
	char	*prefix;

	prefix = "";
	if (flags.hash && nb != 0)
		prefix = "0x";
	str = ft_itoa_base(nb, 16);
	if (!str)
		*len = -1;
	if (flags.minus)
	{
		ft_printstr(prefix, init_flags(), bl_mayus, len);
		ft_printstr(str, init_flags(), bl_mayus, len);
		ft_printpad(' ', flags.width - *len, len);
	}
	else
	{
		if (flags.zero && !flags.minus && flags.dot == -1)
		{
			ft_printstr(prefix, init_flags(), bl_mayus, len);
			ft_printpad('0', flags.width - *len, len);
		}
		else
		{
			ft_printpad(' ', flags.width - (ft_strlen(prefix) + ft_strlen(str)), len);
			ft_printstr(prefix, init_flags(), bl_mayus, len);
		}
		ft_printstr(str, init_flags(), bl_mayus, len);
	}
	free(str);
}

void	ft_printpointer(void *ptr, t_flags flags, int *len)
{
	unsigned long long	pointer;
	char				*str;
	char				*str_pointer;

	pointer = (unsigned long long)ptr;
	str = ft_itoa_base(pointer, 16);
	if (!str)
		*len = -1;
	str_pointer = ft_strjoin("0x", str);
	if (!str_pointer)
		*len = -1;
	ft_printstr(str_pointer, flags, 0, len);
	free(str);
	free(str_pointer);
}
