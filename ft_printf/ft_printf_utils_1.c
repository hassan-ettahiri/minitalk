/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:42:05 by hettahir          #+#    #+#             */
/*   Updated: 2024/11/27 08:52:23 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		count += write(1, &str[i++], 1);
	return (i);
}

int	ft_putchar(int c)
{
	int	count;

	count = write(1, &c, 1);
	return (count);
}

void	ft_putnbr(int n, int *count)
{
	long long	nb;
	char		chiffre;

	nb = n;
	if (nb < 0)
	{
		*count += write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		chiffre = nb + '0';
		*count += write(1, &chiffre, 1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		chiffre = (nb % 10) + '0';
		*count += write(1, &chiffre, 1);
	}
}

void	ft_putunsigned_decimal(unsigned int nb, int *count)
{
	char		chiffre;

	if (nb < 10)
	{
		chiffre = nb + '0';
		*count += write(1, &chiffre, 1);
	}
	if (nb > 9)
	{
		ft_putunsigned_decimal(nb / 10, count);
		chiffre = (nb % 10) + '0';
		*count += write(1, &chiffre, 1);
	}
}

void	convert(size_t nb, int *count)
{
	char		chiffre;

	if (nb < 16)
	{
		if (nb >= 10)
			chiffre = (nb % 16 - 10) + 'a';
		else
			chiffre = (nb % 16) + '0';
		*count += write(1, &chiffre, 1);
	}
	if (nb > 15)
	{
		convert(nb / 16, count);
		if (nb % 16 >= 10)
			chiffre = (nb % 16 - 10) + 'a';
		else
			chiffre = (nb % 16) + '0';
		*count += write(1, &chiffre, 1);
	}
}
