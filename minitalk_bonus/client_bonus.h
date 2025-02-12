#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include "../ft_printf/ft_printf.h"
# include <sched.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_finish(int sig);
void	ft_send_bits(int pid, char i);

#endif