NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
NAME_PRINTF = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_SERVER = server.c
SRC_CLIENT = client.c ft_atoi.c
SRC_SERVER_BONUS = minitalk_bonus/server_bonus.c
SRC_CLIENT_BONUS = minitalk_bonus/client_bonus.c ft_atoi.c
SRC_PRINTF = ./ft_printf/ft_printf_utils_1.c ./ft_printf/ft_printf_utils_2.c ./ft_printf/ft_printf.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

BONUS = $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

bonus: $(BONUS)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS) $(NAME_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(NAME_PRINTF) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(NAME_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(NAME_PRINTF) -o $(NAME_CLIENT_BONUS)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_PRINTF): $(OBJ_PRINTF)
	ar -rcs $(NAME_PRINTF) $(OBJ_PRINTF) 

$(NAME_SERVER): $(OBJ_SERVER) $(NAME_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(NAME_PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(NAME_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(NAME_PRINTF) -o $(NAME_CLIENT)

./%.o: ./%.c client.h server.h ./ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

minitalk_bonus/%.o: minitalk_bonus/%.c minitalk_bonus/client_bonus.h minitalk_bonus/server_bonus.h ./ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_PRINTF) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_PRINTF) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all