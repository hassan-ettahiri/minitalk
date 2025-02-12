/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:05:30 by hettahir          #+#    #+#             */
/*   Updated: 2024/11/24 03:32:54 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	impliment(const char *str, va_list va, int i)
{
	int	count;

	count = 0;
	if (str[i + 1] == 's')
		count = ft_putstr(va_arg(va, char *));
	else if (str[i + 1] == 'c')
		count = ft_putchar(va_arg(va, int));
	else if (str[i + 1] == 'd')
		ft_putnbr(va_arg(va, int), &count);
	else if (str[i + 1] == 'u')
		ft_putunsigned_decimal(va_arg(va, unsigned int), &count);
	else if (str[i + 1] == 'i')
		ft_putnbr(va_arg(va, int), &count);
	else if (str[i + 1] == 'p')
		count = ft_get_adress(va_arg(va, void *));
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		count = ft_print_hex(va_arg(va, unsigned int), str[i + 1]);
	else if (str[i + 1] == '%')
		count = write(1, "%", 1);
	else
		count = write(1, &str[i + 1], 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		index;
	va_list	va;
	int		count;

	index = 0;
	count = 0;
	if (!str || *str == '\0')
		return (0);
	va_start(va, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			count += impliment(str, va, index);
			index++;
		}
		else
			count += write(1, &str[index], 1);
		index++;
	}
	va_end(va);
	return (count);
}
