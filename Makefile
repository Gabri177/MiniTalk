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
CFILE_CLIENTE = cliente.c
CFILE_SERVIDOR = servidor.c
CFILE_C_BONUS = cliente_bonus.c
CFILE_S_BONUS = servidor_bonus.c
OFILE_CLIENTE = cliente.o
OFILE_SERVIDOR = servidor.o
OFILE_C_BONUS = cliente_bonus.o
OFILE_S_BONUS = servidor_bonus.o
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C ./Libft

$(CLIENT): $(OFILE_CLIENTE)
	gcc $(FLAG) -o $(CLIENT) $^ $(LIBFT) 

$(SERVER): $(OFILE_SERVIDOR)
	gcc $(FLAG) -o $(SERVER) $^ $(LIBFT)

%.o : %.c
	gcc $(FLAG) -c $< -o $@

bonus: $(CLIENT_BONUS) $(SERVER_BONUS) $(LIBFT)

$(CLIENT_BONUS): $(OFILE_C_BONUS)
	gcc $(FLAG) -o $(CLIENT_BONUS) $^ $(LIBFT)

$(SERVER_BONUS): $(OFILE_S_BONUS)
	gcc $(FLAG) -o $(SERVER_BONUS) $^ $(LIBFT)
	
clean:
	$(MAKE) clean -C ./Libft
	rm -rf $(OFILE_CLIENTE) $(OFILE_SERVIDOR) $(OFILE_C_BONUS) $(OFILE_S_BONUS)

fclean: clean
	$(MAKE) fclean -C ./Libft
	$(RM) client server client_bonus server_bonus

re: fclean all

.PHONY: clean fclean
