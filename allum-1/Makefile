##
## Makefile for allum-1 in /home/k6/epitech/ELEM/allum-1
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Fri Feb 13 20:38:51 2015
## Last update Sun Feb 22 11:53:14 2015 Cano Chloe
##
NAME	= allum-1
SRC	= main.c \
	term_lib.c \
	select_row.c \
	remove_allum.c \
	start_game.c \
	choose_mode.c \
	input_field.c \
	ia.c \
	ia_move.c
OBJ	= $(addprefix obj/, $(notdir $(SRC:.c=.o)))

CFGLAGS	+= -Wall -Wextra -ansi -pedantic
LDFLAGS	+= -L lib -lmy -lncurses -lm
INCLUDE = -I include -I lib/my/include -ggdb

all: obj/ $(NAME)

obj/:
	mkdir $@

$(NAME): lib/libmy.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

lib/libmy.a:
	make -C lib/my

obj/%.o: src/%.c
	gcc -c -o $@ $< $(CFLAGS) $(INCLUDE)

clean:
	rm -rf obj/
	make -C lib/my clean

fclean: clean
	rm -rf $(NAME)
	make -C lib/my fclean

re: fclean all
