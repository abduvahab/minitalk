# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areheman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 16:12:37 by areheman          #+#    #+#              #
#    Updated: 2022/04/25 15:50:43 by areheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM  = rm -rf

all : server.o client.o
	@make all -C printf
	@$(GCC) $(CFLAGS) server.o printf/libftprintf.a -o $(NAME1)
	@$(GCC) $(CFLAGS) client.o printf/libftprintf.a -o $(NAME2)

bonus : fclean server_bonus.o client_bonus.o
		@make all -C printf
		@$(GCC) $(CFLAGS) server_bonus.o printf/libftprintf.a -o server
		@$(GCC) $(CFLAGS) client_bonus.o printf/libftprintf.a -o client

server.o : server.c 
		@$(GCC) $(CFLAGS) -c $<
client.o : client.c
		@$(GCC) $(CFLAGS) -c $<
server_bonus.o : server_bonus.c
		@$(GCC) $(CFLAGS) -c $<
client_bonus.o : client_bonus.c
		@$(GCC) $(CFLAGS) -c $< 

clean : 
		@make clean -C printf/
		@$(RM) *.o

fclean : clean
		@make fclean -C printf/
		@$(RM) $(NAME1) $(NAME2)

re : clean fclean all

.PHONY : all clean fclean re 
