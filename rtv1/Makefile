##
## Makefile for rtv1 in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Mon Feb  9 18:24:06 2015
## Last update Sun Mar 15 16:20:14 2015 Cano Chloe
##
NAME	= rtv1
SRC	= main.c \
	intersect.c intersect_primitives.c \
	light.c normals.c \
	make_scene.c scene_cross.c \
	mtx_op.c \
	render_img.c \
	rotate.c \
	solve_poly.c \
	vec_op.c vec_op_2.c point_op.c
OBJ	= $(addprefix obj/, $(notdir $(SRC:.c=.o)))

CFLAGS	+= -Wall -Wextra -Werror -O3 -pedantic -ansi
LDFLAGS	+= -L lib -lgraph -lX11 -lXext -lmlx -lm
INCLUDE	= -I include -I lib/include

all: obj/ lib/libgraph.a $(NAME)

lib/libgraph.a:
	make -C lib

obj/:
	mkdir obj/

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

obj/%.o: src/%.c
	gcc -c $(CFLAGS) -o $@ $< $(INCLUDE)

clean:
	rm -rf obj/
	make -C lib clean

fclean: clean
	rm -rf $(NAME)
	make -C lib clean

re: fclean all
