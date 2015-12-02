##
## Makefile for my_select in /home/k6/epitech/MATHS/104intersection/my_select
## 
## Made by Chloe Cano
## Login   <k6@epitech.net>
## 
## Started on  Sun Jan  4 23:48:17 2015
## Last update Sun Jan 11 19:38:06 2015 
##

NAME	= my_select
SRC	= main.c key_controls.c select_lst.c cur_goto.c menu_entry.c \
	select_termcap.c ev_done.c
OBJ	= $(addprefix obj/, $(notdir $(SRC:.c=.o)))
CFLAGS	+= -Wall -Wextra -ansi -pedantic -ggdb
LDFLAGS += -Llib -lmy -lcurses

all: obj/ $(NAME)

obj/:
	mkdir $@

$(NAME): $(OBJ)
	make -C lib/my
	gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

obj/%.o: src/%.c
	gcc $(CFLAGS) -c -o $@ $< -I include

clean:
	make -C lib/my clean
	rm -rf obj/

fclean: clean
	make -C lib/my fclean
	rm -rf $(NAME)

re: fclean all
	make -C lib/my re

