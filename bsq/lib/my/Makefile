##
## Makefile for libmy Makefile in /home/cano_c/rendu/Piscine_C_J11/lib/my
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Mon Oct 20 09:36:01 2014
## Last update Sun Nov 30 17:41:08 2014 Cano Chloe
##

NAME		= libmy.a
SRCS		= get_base_len.c \
		my_putchar.c \
		my_put_nbr.c my_getnbr.c \
		my_putnbr_base.c \
		my_putstr.c my_strlen.c my_putstr_fd.c\
		my_bzero.c \
		my_strncpy.c \
		my_strdup.c \
		my_getopt.c \
		my_strncmp.c \
		blk_new.c \
		lst_new.c \
		lst_insert.c \
		lst_rm.c \
		get_nbr_len.c \
		my_strcmp.c \
		my_strccmp.c \
		my_stracmp.c
OBJS		= $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
INC		= include

all: obj/ $(NAME)

obj/:
	mkdir obj

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp $(NAME) ..

obj/%.o: src/%.c
	gcc -Wall -Wextra -ansi -pedantic -O3 -c -o $@ $< -I$(INC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
