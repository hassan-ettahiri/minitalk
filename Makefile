NAME_SERVER = server
NAME_CLIENT = client
NAME_PRINTF = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_PRINTF = ./ft_printf/ft_prepa.c ./ft_printf/ft_printf_util.c ./ft_printf/ft_printf_util_1.c ./ft_printf/ft_printf_util_2.c ./ft_printf/ft_printf_util_3.c ./ft_printf/ft_printf_util_4.c ./ft_printf/ft_printf.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

all: $(NAME_PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_PRINTF): $(OBJ_PRINTF) ./ft_printf/ft_printf.h
	ar -rcs $(NAME_PRINTF) $(OBJ_PRINTF) 

$(NAME_SERVER): $(OBJ_SERVER) $(NAME_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(NAME_PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(NAME_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(NAME_PRINTF) -o $(NAME_CLIENT)

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_PRINTF)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_PRINTF)

re: fclean all