#ifndef SERVER_H
# define SERVER_H

# include "ft_printf/ft_printf.h"
# include <sched.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define RESET "\033[0m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define YELLOW "\033[33m"

void	ft_handler(int signal, siginfo_t *info, void *s);
void	print_banner(void);
void	clear_screen(void);

#endif