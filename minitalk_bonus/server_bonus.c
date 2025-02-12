#include "server_bonus.h"

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

void	clear_screen()
{
    write(1, "\033[H\033[J", 6);
}

void	print_banner()
{
    write(1, CYAN, 5);
    write(1, " ░▒▓███████▓▒░ ░▒▓████████▓▒░ ░▒▓███████▓▒░  ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓████████▓▒░ ░▒▓███████▓▒░  \n░▒▓█▓▒░        ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n░▒▓█▓▒░        ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░  ░▒▓█▓▒▒▓█▓▒░  ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n ░▒▓██████▓▒░  ░▒▓██████▓▒░   ░▒▓███████▓▒░   ░▒▓█▓▒▒▓█▓▒░  ░▒▓██████▓▒░   ░▒▓███████▓▒░  \n       ░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░   ░▒▓█▓▓█▓▒░   ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n       ░▒▓█▓▒░ ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░   ░▒▓█▓▓█▓▒░   ░▒▓█▓▒░        ░▒▓█▓▒░░▒▓█▓▒░ \n░▒▓███████▓▒░  ░▒▓████████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░    ░▒▓██▓▒░    ░▒▓████████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ \n", 1586);
    write(1, RESET "\n", 5);
}

void	print_array(char *t, int *i, int *bit)
{
	ft_printf("%s", *t);
	*i = 0;
	*bit = 0;
}

void	store_in_array(char *t, int *c)
{
	static int	i;

	t[i] = *c;
	t[i + 1] = '\0';
	i++;
}
void	meme(char *t, int *c, int *bit, int *j)
{
	int	i;

	i = 0;
	while (i < 7000000)
	{
		t[i] = 0;
		i++;
	}
	*c = 0;
	*bit = 0;
	*j = 0;
	ft_printf("\n");
}

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;
	static int	pid;
	static int j;
	static char t[7000000];
	(void)s;

	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		meme(t, &i, &bit, &j);
	}
	if (signal == SIGUSR1)
		i += (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
		{
			ft_printf("%s", t);
			meme(t, &i, &bit, &j);
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			t[j] = (char)i;
			t[j + 1] = '\0';
			j++;
			i = 0;
			bit = 0;
		}
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
	sigaction(SIGUSR1, &si, NULL);
	sigaction(SIGUSR2, &si, NULL);
	while (1)
		pause ();
    return (0);
}
