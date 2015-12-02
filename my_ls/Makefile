##
## Makefile for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Mon Nov 24 20:08:44 2014
## Last update Sun Nov 30 17:37:58 2014 Cano Chloe
##

NAME	= my_ls
SRC	= my_ls.c get_entry.c print_long.c get_dir_entries.c \
	get_long.c print_mode.c print_reg.c sort_entry.c \
	ls_rec.c file_utils.c padding.c ls_files_dir.c
OBJ	= $(addprefix obj/, $(notdir $(SRC:.c=.o)))
CFLAGS	+= -Wall -Wextra -ansi -pedantic -ggdb
LDFLAGS	+= -Llib -lmy
INC	= include

all: obj/ include/my.h $(NAME)

obj/:
	mkdir obj

include/my.h:
	cp lib/my/include/my.h include

$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LDFLAGS)

obj/%.o: src/%.c
	gcc $(CFLAGS) -c -o $@ $< -I $(INC)

clean:
	make -C lib/my clean
	rm -rf obj

fclean: clean
	make -C lib/my fclean
	rm -rf $(NAME)

re: fclean all
	make -C lib/my re
