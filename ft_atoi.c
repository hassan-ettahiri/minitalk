/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:00:31 by hettahir          #+#    #+#             */
/*   Updated: 2025/02/12 01:35:43 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\n'
		|| c == '\r');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	nbr;
	int	signal;
	int	aux;

	nbr = 0;
	aux = 0;
	signal = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			signal = -1;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str++ - 48);
		if (aux > nbr)
		{
			if (signal < 0)
				return (-1);
			else
				return (0);
		}
		aux = nbr;
	}
	return (nbr * signal);
}
