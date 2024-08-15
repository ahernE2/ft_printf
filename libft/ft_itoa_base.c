/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:27:53 by alejhern          #+#    #+#             */
/*   Updated: 2024/08/15 11:52:49 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countdigits_base(unsigned int nb, int base)
{
	size_t	len;

	len = 1;
	while (nb / base != 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}

static unsigned int	get_unsigned_nb(int nb, int base)
{
	if (nb < 0 && base == 10)
		return ((unsigned int)(-nb));
	else
		return (nb);
}

char	*ft_itoa_base(int nb, int base)
{
	unsigned int	nb_unsigned;
	size_t			digits;
	char			*str;
	char			*base_digits;

	base_digits = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	nb_unsigned = get_unsigned_nb(nb, base);
	digits = ft_countdigits_base(nb_unsigned, base);
	if (nb < 0 && base == 10)
		digits += 1;
	str = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (digits--)
	{
		str[digits] = base_digits[nb_unsigned % base];
		nb_unsigned /= base;
	}
	if (nb < 0 && base == 10)
		str[0] = '-';
	return (str);
}
