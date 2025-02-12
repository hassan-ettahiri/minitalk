/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 06:13:07 by hettahir          #+#    #+#             */
/*   Updated: 2025/02/12 06:13:59 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	ft_finish(int sig)
{
	if (sig == SIGUSR1)
		return ;
	else if (sig == SIGUSR2)
		ft_printf("Message delivred succeflly !\n");
}

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		signal(SIGUSR1, ft_finish);
		if ((i & (0x01 << bit)) != 0)
		{
			if ((kill(pid, SIGUSR1)) == -1)
			{
				ft_printf("Wrong pid !\n");
				exit(1);
			}
		}
		else
		{
			if ((kill(pid, SIGUSR2)) == -1)
			{
				ft_printf("Wrong pid !\n");
				exit(1);
			}
		}
		bit++;
		pause();
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		signal(SIGUSR2, ft_finish);
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("Wrong pid !\n");
			return (1);
		}
		while (argv[2][i] != '\0')
			ft_send_bits(pid, argv[2][i++]);
		ft_send_bits(pid, '\0');
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
}
