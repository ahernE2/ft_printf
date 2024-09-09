/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:11:03 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/09 02:54:41 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.dot = -1;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

t_flags	parse_flags(const char **str)
{
	t_flags	flags;

	flags = init_flags();
	while (ft_strchr("0-.# +", **str))
	{
		if (**str == '0')
			flags.zero = 1;
		else if (**str == '-')
			flags.minus = 1;
		else if (**str == '.')
			flags.dot = ft_atoi(++(*str));
		else if (**str == '#')
			flags.hash = 1;
		else if (**str == ' ')
			flags.space = 1;
		else if (**str == '+')
			flags.plus = 1;
		(*str)++;
	}
	if (ft_isdigit(**str))
		flags.width = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	return (flags);
}

void	ft_printstr_flags(t_flags flags, int str_len, int *len)
{
	if (flags.width > str_len && !flags.minus)
	{
		while (flags.width-- > str_len)
			ft_printchar(' ', init_flags(), 0, len);
	}
	else if (flags.width > str_len && flags.minus)
	{
		while (flags.width-- > str_len)
			ft_printchar(' ', init_flags(), 0, len);
	}
}

void	ft_printpad(char pad_char, int pad_len, int *len)
{
	while (pad_len > 0)
	{
		ft_printchar(pad_char, init_flags(), 0, len);
		pad_len--;
	}
}
