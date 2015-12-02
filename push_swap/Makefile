##
## Makefile for push_swap in /home/cano_c/rendu/ELEM/CPE_2014_Pushswap
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Mon Dec  1 19:24:37 2014
## Last update Thu Dec  4 11:27:08 2014 
##

NAME	= push_swap
SRC	= push_swap.c ps_op.c quick_sort.c
OBJ	= $(addprefix obj/, $(notdir $(SRC:.c=.o)))
CFLAGS	+= -Wall -Wextra -ansi -pedantic -ggdb
LDFLAGS	+= -Llib -lmy
INC	= -I include

all: obj/ include/my.h $(NAME)

obj/:
	mkdir $@

$(NAME): $(OBJ)
	make -C lib/my
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

include/%.h: lib/my/include/%.h
	cp $< $@

obj/%.o: src/%.c
	gcc $(CFLAGS) -c -o $@ $< $(INC)

clean:
	make -C lib/my clean
	rm -rf $(OBJ)

fclean: clean
	make -C lib/my fclean
	rm -rf $(NAME)

re: fclean all
	make -C lib/my re
