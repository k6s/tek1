##
## Makefile for fdf in /home/cano_c/rendu/IGRAPH/MLU_2014_fdf
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Tue Nov 18 16:51:09 2014
## Last update Sun Nov 23 23:01:32 2014 
##

NAME	= fdf
SRC	= main.c fdf.c map.c get_next_line.c disp_utils.c get_next_line_2.c \
	events.c
OBJ	= $(addprefix obj/, $(notdir $(SRC:.c=.o)))
CFLAGS	+= -Wall -Wextra -ansi -pedantic -O3 -ggdb
LDFLAGS += -Lgraph_lib -lgraph -Llib -lmy -LX11 -lmlx -lXext -lX11

all: include/graph_lib.h obj/ $(NAME)

obj/:
	mkdir obj

include/graph_lib.h:
	cp graph_lib/include/graph.h include/
	cp graph_lib/include/keys.h include/
	cp lib/my/my.h include

$(NAME): $(OBJ)
	make -C graph_lib
	make -C lib/my
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

obj/%.o: src/%.c
	gcc $(CFLAGS) -c -o $@ $< -I include

clean:
	make -C graph_lib clean
	make -C lib/my clean
	rm -rf $(OBJ)

fclean: clean
	make -C graph_lib fclean
	make -C lib/my fclean
	rm -rf $(NAME)

re: fclean all
