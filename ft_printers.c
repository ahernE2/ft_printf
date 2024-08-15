# include "ft_printf.h"

int	ft_printchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int ft_printstr(char *str, unsigned int bl_mayus)
{
	int		len;
	char	c;

	if (!str)
		return (ft_printstr("(null)", 0));
	len = 0;
	while (*str)
	{
		c = *str;
		if (bl_mayus)
			c = ft_toupper(c);
		if (ft_printchar(c) != 1)
			return (-1);
		len++;
		str++;
	}
	return (len);
}

static int ft_print_nbr_base(unsigned long long nb, int base)
{
    int len = 0;
    if (nb >= base)
        len += ft_print_nbr_base(nb / base, base);
    
    if (ft_printchar("0123456789abcdef"[nb % base]) != 1)
        return -1;

    return len + 1;
}

 int ft_printnbr(int nb, int base, unsigned int isunsigned, unsigned int bl_mayus)
{
	int		len;
	char	*str;

	if (isunsigned && base == 10)
		return (ft_print_nbr_base((unsigned int)nb, base));
	str = ft_itoa_base(nb, base);
	if (!str)
		return (-1);
	len = ft_printstr(str, bl_mayus);
	free(str);
	str = NULL;
	return (len);
}

int	ft_printpointer(void *ptr)
{
	unsigned long long	pointer;
	int					len;

	pointer = (unsigned long long)ptr;
	len = 0;
	len = ft_printstr("0x", 0);
	if (len != 2)
		return (-1);
	len += ft_print_nbr_base(pointer, 16);
    if ((len - 2) == -1)
        len = -1;
	return (len);
}