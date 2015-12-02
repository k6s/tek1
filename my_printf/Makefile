##
## Makefile for libmy Makefile in /home/cano_c/rendu/Piscine_C_J11/lib/my
## 
## Made by
## Login   <cano_c@epitech.net>
## 
## Started on  Mon Oct 20 09:36:01 2014
## Last update Sun Nov 16 20:16:08 2014 Cano Chloe
##

NAME		= libmy.a
SRCS		= get_base_len.c \
		my_putchar.c \
		my_put_nbr.c my_getnbr.c \
		my_putnbr_base.c \
		my_putstr.c my_strlen.c \
		my_bzero.c
OBJS		= $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
INC		= include
include printf/Makefile

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) $(POBJ)
	ranlib $(NAME)

obj/%.o: src/%.c
	gcc -Wall -Wextra -O3 -c -o $@ $< -I$(INC) -ggdb



clean: pclean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
