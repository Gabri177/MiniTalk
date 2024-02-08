# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 20:32:40 by yugao             #+#    #+#              #
#    Updated: 2024/02/08 03:58:49 by yugao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Werror -Wall -Wextra
LIBFT = ./Libft/libft.a

all: client server

client: $(LIBFT)
	gcc $(FLAG) -o client cliente.c $(LIBFT) -I ./ 

server: $(LIBFT)
	gcc $(FLAG) -o server servidor.c $(LIBFT) -I ./ 

bonus: client_bonus server_bonus

client_bonus: $(LIBFT)
	gcc $(FLAG) -o client_bonus cliente_bonus.c $(LIBFT) -I ./ 

server_bonus: $(LIBFT)
	gcc $(FLAG) -o server_bonus servidor_bonus.c $(LIBFT) -I ./ 

$(LIBFT):
	$(MAKE) -C ./Libft
	
%.o : %.c
	gcc -c $(FLAG) $< -I ./ -o $@
	
clean:
	$(MAKE) clean -C ./Libft

fclean: clean
	$(MAKE) fclean -C ./Libft
	$(RM) client server client_bonus server_bonus

re: fclean all

.PHONY: clean fclean all re bonus client server client_bonus server_bonus
