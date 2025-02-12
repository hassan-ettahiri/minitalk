#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sched.h>
#include <stdlib.h>
#include "../ft_printf/ft_printf.h"

int	ft_atoi(const char *str);
void	ft_finish(int sig);
void	ft_send_bits(int pid, char i);

#endif