/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 03:55:46 by alejhern          #+#    #+#             */
/*   Updated: 2024/09/09 03:55:51 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main(void)
{
	char	*str;
	int		num;
	unsigned int	hex_num;
	void	*ptr;
	int		len_ft;
	int		len_orig;

	// Test básico de string y puntero
	str = "Hola, mundo";
	ptr = &str;
	len_ft = ft_printf("FT_PRINTF: String: %s, Pointer: %p\n", str, ptr);
	len_orig = printf("PRINTF: String: %s, Pointer: %p\n", str, ptr);
	printf("FT_PRINTF Len: %d | PRINTF Len: %d\n\n", len_ft, len_orig);

	// Test de números enteros con flags
	num = 42;
	len_ft = ft_printf("FT_PRINTF: Entero: %+d, Con espacio: % d\n", num, num);
	len_orig = printf("PRINTF: Entero: %+d, Con espacio: % d\n", num, num);
	printf("FT_PRINTF Len: %d | PRINTF Len: %d\n\n", len_ft, len_orig);

	// Test de enteros con ancho de campo y relleno de ceros
	len_ft = ft_printf("FT_PRINTF: Entero con ancho y ceros: %010d\n", num);
	len_orig = printf("PRINTF: Entero con ancho y ceros: %010d\n", num);
	printf("FT_PRINTF Len: %d | PRINTF Len: %d\n\n", len_ft, len_orig);

	// Test de hexadecimales (mayúscula y minúscula) con hash
	hex_num = 255;
	len_ft = ft_printf("FT_PRINTF: Hexadecimal: %#x, Hexadecimal (MAYÚS): %#X\n", hex_num, hex_num);
	len_orig = printf("PRINTF: Hexadecimal: %#x, Hexadecimal (MAYÚS): %#X\n", hex_num, hex_num);
	printf("FT_PRINTF Len: %d | PRINTF Len: %d\n\n", len_ft, len_orig);

	// Test de enteros con precisión
	num = 123;
	len_ft = ft_printf("FT_PRINTF: Entero con precisión: %.5d\n", num);
	len_orig = printf("PRINTF: Entero con precisión: %.5d\n", num);
	printf("FT_PRINTF Len: %d | PRINTF Len: %d\n\n", len_ft, len_orig);

	// Test de string con precisión
	len_ft = ft_printf("FT_PRINTF: String con precisión: %.5s\n", str);
	len_orig = printf("PRINTF: String con precisión: %.5s\n", str);
	printf("FT_PRINTF Len: %d | PRINTF Len: %d\n\n", len_ft, len_orig);

	// Test de caracteres
	len_ft = ft_printf("FT_PRINTF: Carácter: %c\n", 'A');
	len_orig = printf("PRINTF: Carácter: %c\n", 'A');
	printf("FT_PRINTF Len: %d | PRINTF Len: %d\n\n", len_ft, len_orig);

	// Test de caracteres con ancho de campo
	len_ft = ft_printf("FT_PRINTF: Carácter con ancho: %5c\n", 'B');
	len_orig = printf("PRINTF: Carácter con ancho: %5c\n", 'B');
	printf("FT_PRINTF Len: %d | PRINTF Len: %d\n\n", len_ft, len_orig);

	// Test de impresión del símbolo %
	len_ft = ft_printf("FT_PRINTF: Porcentaje %%\n");
	len_orig = printf("PRINTF: Porcentaje %%\n");
	printf("FT_PRINTF Len: %d | PRINTF Len: %d\n\n", len_ft, len_orig);

	return (0);
}

