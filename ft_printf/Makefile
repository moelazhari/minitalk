# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 15:15:37 by mazhari           #+#    #+#              #
#    Updated: 2022/02/16 16:42:51 by mazhari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 

FLAGS = -Wall -Wextra -Werror 

LIB = ar rc

NAME = ftprintf.a

SRCS = ft_printf.c \
	   ft_printf_utils.c \

HEADER = ft_printf.h

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) -c $(SRCS)
	$(LIB) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

