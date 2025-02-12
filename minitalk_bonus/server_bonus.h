#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include "../ft_printf/ft_printf.h"
# include <sched.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define YELLOW "\033[33m"

typedef struct s_server
{
	int		bit;
	int		i;
	int		pid;
	int		j;
	char	t[7000000];
}			t_server;

void		clear_screen(void);
void		print_banner(void);
void		print_array(char *t, int *i, int *bit);
void		store_in_array(char *t, int *i, int *j, int *bit);
void		meme(char *t, int *c, int *bit, int *j);
void		print_string(t_server *ser, siginfo_t *info);
void		ft_handler(int signal, siginfo_t *info, void *s);

#endif