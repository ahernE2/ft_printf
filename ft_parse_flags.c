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
	flags.width = -1;
	flags.dot = -1;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

static t_flags parse_nbr_flags(t_flags flags, const char **str)
{
	while (**str == '.' || ft_isdigit(**str))
	{
		if (**str == '.')
		{
			(*str)++;
			if (ft_isdigit(**str))
				flags.dot = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
			continue;
		}
		else if (ft_isdigit(**str))
		{
			flags.width = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
			continue;
		}
		(*str)++;
	}
	return (flags);
}

t_flags	parse_flags(const char **str)
{
	t_flags	flags;

	flags = init_flags();
	while (ft_strchr("0-# +", **str))
	{
		if (**str == '0' && flags.width == -1 && flags.minus == 0)
			flags.zero = 1;
		else if (**str == '-')
			flags.minus = 1;
		else if (**str == '#')
			flags.hash = 1;
		else if (**str == ' ')
			flags.space = 1;
		else if (**str == '+')
			flags.plus = 1;
		(*str)++;
	}
	flags = parse_nbr_flags(flags, str);
	return (flags);
}

void	ft_printpad(char pad_char, int pad_len, int *len)
{
	while (pad_len-- > 0)
		ft_printchar(pad_char, init_flags(), 0, len);
}

void	ft_printnbr_flags(int nb, t_flags flags, int total_len, char *prefix, int *len)
{
	if (prefix)
	{
		if (flags.zero && !flags.minus && flags.dot == -1)
		{
			ft_printstr(prefix, init_flags(), nb, len);
			ft_printpad('0', flags.width - *len, len);
		}
		else
		{
			ft_printpad(' ', flags.width - (ft_strlen(prefix) + total_len), len);
			ft_printstr(prefix, init_flags(), nb, len);
		}
		return ;
	}
	if (nb < 0 || flags.plus || flags.space)
		total_len++;
	if (nb < 0)
		ft_printchar('-', init_flags(), 0, len);
	else if (flags.plus)
		ft_printchar('+', init_flags(), 0, len);
	else if (flags.space)
		ft_printchar(' ', init_flags(), 0, len);
	if (!flags.minus && flags.zero && flags.dot == -1)
		ft_printpad('0', flags.width - total_len, len);
}
