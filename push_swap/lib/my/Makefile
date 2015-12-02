##
## Makefile for libmy Makefile in /home/cano_c/rendu/Piscine_C_J11/lib/my
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Mon Oct 20 09:36:01 2014
## Last update Mon Dec  1 20:23:39 2014 
##

NAME		= libmy.a
SRCS		= get_base_len.c \
		is_nbr.c \
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
		lst_new_data.c \
		lst_insert.c \
		lst_stack.c \
		lst_sclear.c \
		get_nbr_len.c \
		my_strcmp.c \
		my_strccmp.c \
		my_stracmp.c
OBJS		= $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
INC		= include

all: obj/ $(NAME)

obj/:
	mkdir $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp $(NAME) ..

obj/%.o: src/%.c
	gcc -Wall -Wextra -ansi -pedantic -O3 -c -o $@ $< -I$(INC) -ggdb

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
