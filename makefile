# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 16:46:23 by mazhari           #+#    #+#              #
#    Updated: 2022/02/16 17:06:27 by mazhari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra

FTPRINTF_DIR = ft_printf
FTPRINTF_LIB = $(FTPRINTF_DIR)/ftprintf.a

NAME = minitalk
CLIENT = client
SERVER = server

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_CLIENT = $(SRCS_CLIENT:%.c=%.o)
OBJS_SERVER = $(SRCS_SERVER:%.c=%.o)

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(CLIENT): $(OBJS_CLIENT) $(FTPRINTF_LIB)
	$(CC) $(FLAGS) $(FTPRINTF_LIB) $(OBJS_CLIENT) -o $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(FTPRINTF_LIB)
	$(CC) $(FLAGS) $(FTPRINTF_LIB) $(OBJS_SERVER) -o $(SERVER)

$(FTPRINTF_LIB):
	$(MAKE) -C $(FTPRINTF_DIR)

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) clean -C $(FTPRINTF_DIR)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	$(MAKE) fclean -C $(FTPRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re bonus