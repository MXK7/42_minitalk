# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 11:30:24 by mpoussie          #+#    #+#              #
#    Updated: 2023/07/21 08:29:13 by mpoussie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = src/utils.c src/client.c
SERVER_SRCS = src/utils.c src/server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): client server

client: $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o client

server: $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o server

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	$(RM) client server

re: fclean all

.PHONY: all client server clean fclean re