#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <sched.h>  
#include "ft_printf/ft_printf.h"

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

void clear_screen() {
    write(1, "\033[H\033[J", 6);
}

void print_banner() {
    write(1, CYAN, 5);
    write(1, " ░▒▓███████▓▒░ ░▒▓████████▓▒░ ░▒▓███████▓▒░  ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓████████▓▒░ ░▒▓███████▓▒░  \n░▒▓█▓▒░        ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n░▒▓█▓▒░        ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒▒▓█▓▒░  ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n ░▒▓██████▓▒░  ░▒▓██████▓▒░   ░▒▓███████▓▒░   ░▒▓█▓▒▒▓█▓▒░  ░▒▓██████▓▒░   ░▒▓███████▓▒░  \n       ░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░   ░▒▓█▓▓█▓▒░   ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n       ░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░   ░▒▓█▓▓█▓▒░   ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n░▒▓███████▓▒░  ░▒▓████████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░    ░▒▓██▓▒░    ░▒▓████████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ \n", 1586);
    write(1, RESET "\n", 5);
}

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;
	static int	pid;
	(void)s;

	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i = 0;
		bit = 0;
	}
	if (signal == SIGUSR1)
		i += (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write (1, &i, 1);
		bit = 0;
		i = 0;
	}
	usleep(800);
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    pid_t server_pid;
	struct sigaction si;

    server_pid = getpid();
    clear_screen();
    print_banner();
    write(1, GREEN "server PID: " "\033[0m", 17);
    ft_printf("%d\n", server_pid);
	si.sa_sigaction = ft_handler;
	si.sa_flags = SA_SIGINFO;
	sigemptyset(&si.sa_mask);
	sigaction(SIGUSR1, &si, NULL);
	sigaction(SIGUSR2, &si, NULL);
	while (1)
		pause ();
    return (0);
}
