# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 20:32:40 by yugao             #+#    #+#              #
#    Updated: 2024/02/07 22:57:54 by yugao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = servidor.c cliente.c
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./ 

all: do server client
bonus: server client

server: 
	$(CC) -o server servidor.c ./Libft/libft.a $(INCLUDES)

client: 
	$(CC) -o client cliente.c ./Libft/libft.a $(INCLUDES)

%.o: %.c
	$(CC) -c $(FLAGS) $< $(INCLUDES) -o $@

do:
	$(MAKE) -C Libft

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C Libft clean
	
fclean: clean
	rm -f server client Libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re