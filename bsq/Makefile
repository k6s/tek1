##
## Makefile for bsq in /home/cano_c/rendu/ELEM/CPE_2014_bsq
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Mon Dec 22 19:49:11 2014
## Last update Mon Jan 12 13:43:03 2015 
##

NAME	= bsq
SRC	= get_next_line.c get_next_line_2.c main.c output.c map.c square.c
OBJ	= $(addprefix obj/, $(notdir $(SRC:.c=.o)))
INC	= ./include/
CFLAGS	+= -Wall -Wextra -ansi -pedantic -O3
LDFLAGS	+= -L lib -lmy

all: obj/ include/my.h $(NAME)

obj/:
	mkdir $@

include/my.h: lib/my/include/my.h
	cp $< $@

$(NAME): $(OBJ)
	make -C lib/my/
	gcc $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

obj/%.o: src/%.c
	gcc $(CFLAGS) -c -o $@ $< -I $(INC)

clean:
	make -C lib/my/ clean
	rm -rf obj/

fclean: clean
	make -C lib/my/ fclean
	rm -rf $(NAME)

re: fclean all
	make -C lib/my/ re
