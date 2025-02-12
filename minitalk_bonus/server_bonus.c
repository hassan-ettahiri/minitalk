#include "server_bonus.h"

void	print_string(t_server *ser, siginfo_t *info)
{
	ft_printf("%s\n", ser->t);
	meme(ser->t, &ser->i, &ser->bit, &ser->j);
	kill(info->si_pid, SIGUSR2);
}

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static t_server	ser;

	(void)s;
	if (ser.pid != info->si_pid)
	{
		ser.pid = info->si_pid;
		meme(ser.t, &ser.i, &ser.bit, &ser.j);
	}
	if (signal == SIGUSR1)
		ser.i += (0x01 << ser.bit);
	ser.bit++;
	if (ser.bit == 8)
	{
		if (ser.i == 0)
			print_string(&ser, info);
		else
			store_in_array(ser.t, &ser.i, &ser.j, &ser.bit);
	}
	usleep(800);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	si;

	server_pid = getpid();
	clear_screen();
	print_banner();
	write(1, GREEN "server PID: ", 17);
	ft_printf("%d\n", server_pid);
	si.sa_sigaction = ft_handler;
	si.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &si, NULL);
	sigaction(SIGUSR2, &si, NULL);
	while (1)
		pause();
	return (0);
}
