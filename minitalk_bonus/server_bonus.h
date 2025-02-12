#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <sched.h>
#include "../ft_printf/ft_printf.h"

void	ft_handler(int signal, siginfo_t *info, void *s);
void print_banner();
void clear_screen();

#endif