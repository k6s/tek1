##
## Makefile for libgraph in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1/lib
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Mon Feb 23 14:01:23 2015 
## Last update Mon Feb 23 14:01:33 2015 
##

NAME	= libgraph.a
SRC	= draw_line.c draw_circle.c draw_ellipse.c \
	new_img.c img_put_pixel.c img_put_line.c img_get_color.c \
	img_fill_inside.c color_op.c
OBJ	= $(addprefix obj/,$(notdir $(SRC:.c=.o)))

all:: obj $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $(NAME)

obj:
	mkdir obj

obj/%.o: src/%.c
	gcc -Wall -Wextra -c -o $@ $< -I include -I X11

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
