CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils_1.c ft_printf_utils_2.c
SRCS_BONUS = ft_printf_bonus.c ft_printf_utils_1_bonus.c ft_printf_utils_2_bonus.c
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}

%.o: %.c ft_printf.h ft_printf_bonus.c
	cc ${CFLAGS} -c $< -o $@
	ar -rcs ${NAME} $@

bonus: ${OBJS_BONUS}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all