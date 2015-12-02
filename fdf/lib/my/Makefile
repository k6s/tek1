##
## Makefile for eval_expr in /home/cano_c/rendu/Piscine_C_eval_expr
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Sun Oct 26 22:45:57 2014
## Last update Wed Nov 19 16:53:41 2014 
##

NAME	= ../libmy.a
SRCS	= my_putchar.c my_getnbr.c my_putstr.c \
	my_memcpy.c my_bzero.c my_strlen.c \
	my_strcmp.c my_memcmp.c my_memmove.c \
	my_str_to_wordtab.c my_strncpy.c my_put_nbr.c
OBJS	= $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
OBJ	= $(SRCS:.c=.o)
CFLAGS	+= -Wall -Wextra -O3
INC	= .

all: ../../include/my.h obj ../../include/my.h $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

obj:
	mkdir obj/

../../include/my.h: my.h
	cp $< $@

obj/%.o: src/%.c
	gcc $(CFLAGS) -c -o $@ $< -I $(INC) $(LDFLAGS) -ggdb3

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
