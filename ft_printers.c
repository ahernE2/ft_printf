/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:59:05 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/09 22:13:08 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(char c, t_flags flags, int bl_mayus, int *len)
{
	if (*len == -1)
		return ;
	if (!flags.minus && flags.width > 1)
		ft_printpad(' ', flags.width - 1, len);
	if (*len == -1)
		return ;
	if (bl_mayus)
		c = ft_toupper(c);
	if (write(1, &c, 1) != 1)
		*len = -1;
	else
		(*len)++;
	if (flags.minus && flags.width > 1)
		ft_printpad(' ', flags.width - 1, len);
}

void	ft_printstr(char *str, t_flags flags, int bl_mayus, int *len)
{
	int	str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flags.dot >= 0 && flags.dot < str_len)
		str_len = flags.dot;
	if (!flags.minus && flags.width > str_len)
		ft_printpad(' ', flags.width - 1, len);
	while (*str && str_len--)
		ft_printchar(*str++, init_flags(), bl_mayus, len);
	if (!flags.minus && flags.width > str_len)
		ft_printpad(' ', flags.width - 1, len);
}

void	ft_printnbr(int nb, t_flags flags, int *len)
{
	char	*str;
	int		padding;

	str = ft_itoa(nb);
	if (!str)
	{
		*len = -1;
		return ;
	}
	if (nb < 0)
		str++;
	padding = 0;
	if (flags.dot > (int) ft_strlen(str))
		padding = flags.dot - ft_strlen(str);
	if (!flags.minus && (!flags.zero || flags.dot != -1))
		ft_printpad(' ', flags.width - ft_strlen(str)
			- padding - (nb < 0), len);
	ft_printnbr_flags(nb, flags, ft_strlen(str) - padding, len);
	ft_printpad('0', padding, len);
	ft_printstr(str, init_flags(), 0, len);
	if (flags.minus)
		ft_printpad(' ', flags.width - ft_strlen(str)
			- padding - (nb < 0), len);
	free(str - (nb < 0));
}

void	ft_printnbr_hex(unsigned int nb, t_flags flags, int bl_mayus, int *len)
{
	char	*str;

	flags.prefix = "";
	if (flags.hash && nb != 0)
		flags.prefix = "0x";
	str = ft_itoa_base(nb, 16);
	if (!str)
	{
		*len = -1;
		return ;
	}
	if (flags.minus)
	{
		ft_printstr(flags.prefix, init_flags(), bl_mayus, len);
		ft_printstr(str, init_flags(), bl_mayus, len);
		ft_printpad(' ', flags.width - *len, len);
	}
	else
	{
		ft_printnbr_flags(bl_mayus, flags, ft_strlen(str), len);
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
