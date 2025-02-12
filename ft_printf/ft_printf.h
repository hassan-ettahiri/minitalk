/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:46:59 by hettahir          #+#    #+#             */
/*   Updated: 2025/02/12 01:15:07 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putstr(char *str);
int		ft_putchar(int c);
void	ft_putnbr(int n, int *count);
void	ft_putunsigned_decimal(unsigned int nb, int *count);
void	convert(size_t nb, int *count);
int		ft_get_adress(void *ptr);
void	convert_hex(size_t nb, const char format, int *count);
int		ft_print_hex(unsigned int num, const char format);

int		ft_printf(const char *str, ...);

#endif