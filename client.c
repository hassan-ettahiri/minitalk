#include "client.h"

void	ft_finish(int sig)
{
	if (sig == SIGUSR1)
		return ;
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
				exit(1);
		}
		else
		{
			if ((kill(pid, SIGUSR2)) == -1)
				exit(1);
		}
		bit++;
		pause();
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			return (1);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
}
