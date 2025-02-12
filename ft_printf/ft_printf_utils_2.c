/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:44:00 by hettahir          #+#    #+#             */
/*   Updated: 2024/11/27 08:59:45 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_adress(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "0x0", 3));
	count += write(1, "0x", 2);
	convert((size_t)ptr, &count);
	return (count);
}

void	convert_hex(size_t nb, const char format, int *count)
{
	char		chiffre;

	if (nb < 16)
	{
		if (nb >= 10)
			chiffre = (nb % 16 - 10) + (format - ('x' - 'a'));
		else
			chiffre = (nb % 16) + '0';
		*count += write(1, &chiffre, 1);
	}
	if (nb > 15)
	{
		convert_hex(nb / 16, format, count);
		if (nb % 16 >= 10)
			chiffre = (nb % 16 - 10) + (format - ('x' - 'a'));
		else
			chiffre = (nb % 16) + '0';
		*count += write(1, &chiffre, 1);
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	int	cmp;
	int	count;

	cmp = 0;
	count = 0;
	if (num == 0)
		return (cmp + write(1, "0", 1));
	else
		convert_hex(num, format, &count);
	return (cmp + count);
}
