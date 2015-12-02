##
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Wed Oct 29 16:58:05 2014
## Last update Sat Nov 22 23:30:29 2014 
##

NAME	= libgraph.a
SRC	= draw_line.c draw_circle.c draw_ellipse.c \
	new_img.c img_put_pixel.c img_put_line.c img_get_color.c \
	img_put_circle.c img_fill_inside.c proj.c
OBJ	= $(addprefix obj/,$(notdir $(SRC:.c=.o)))

all:: obj $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $(NAME)

obj:
	mkdir obj

obj/%.o: src/%.c
	gcc -Wall -Wextra -c -o $@ $< -I include -I X11 -ggdb -I ../include

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
