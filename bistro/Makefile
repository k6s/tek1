##
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Sun Oct 26 22:45:57 2014
## Last update Sun Nov  9 17:04:07 2014 Cano Chloe
##

NAME	= calc
SRCS	= main.c eval_expr.c do-op.c misc.c stack.c parse.c \
	is_valid.c zero.c \
	inf_add.c inf_sub.c inf_mul.c inf_div.c inf_mod.c \
	get_base_idx.c op_utils.c is_op.c parse_par.c
OBJS	= $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
CFLAGS	+= -Wall -Wextra -ansi --pedantic -O3
INC	= include
LIB	= libmy.a

all: obj $(LIB) $(NAME)

$(NAME): lib/$(LIB) $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -I $(INC) -Llib -lmy

$(LIB):
	make -C lib/my

obj:
	mkdir obj/

obj/%.o: src/%.c
	gcc $(CFLAGS) -c -o $@ $< -I $(INC) -ggdb3

clean:
	make -C lib/my clean
	rm -rf $(OBJS)

fclean: clean
	make -C lib/my fclean
	rm -rf $(NAME)

re: fclean all
