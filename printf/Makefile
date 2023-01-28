# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areheman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 15:18:23 by areheman          #+#    #+#              #
#    Updated: 2022/04/05 11:58:14 by areheman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RANLIB = ranlib
RM = rm -rf
LIB_DIR = libft/
LIBFT_LIB = libft.a

SRC = ft_printf.c ft_treatments.c ft_treat_char.c ft_treat_percent.c ft_treat_str.c ft_treat_demi.c ft_convert.c ft_treat_point.c\
		ft_treat_hexa.c ft_treat_uint.c

OBJ = $(SRC:.c=.o) $(SRC_LIB:.c=.o)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
		@make all -C $(LIB_DIR)
		@cp $(LIB_DIR)/$(LIBFT_LIB) $@
		@$(AR) $@ $^  
		@$(RANLIB) $@ 

clean : 
		@make clean -C $(LIB_DIR)
		@$(RM) $(OBJ)

fclean : clean
		@make fclean -C $(LIB_DIR)
		@$(RM) $(NAME)

re : clean fclean all 

.PHONY : all fclean clean re 


