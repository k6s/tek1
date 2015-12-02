##
## Makefile for minishell1 in /home/cano_c/rendu/UNIX/PSU_2014_minishell1
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Tue Jan 13 15:34:51 2015
## Last update Fri Jan 30 18:58:20 2015 
##

NAME	= mysh
SRCS	= main.c get_next_line.c get_next_line_2.c \
				builtins_tree.c progs_tree.c \
				env_builtins.c my_exit.c my_cd.c \
				sh_exe.c \
				sh_cmd.c \
				sh_env.c \
				sh_free.c \
				sh_signal.c \
				sh_termcap.c \
				sh_hist.c \
				sh_key.c \
				my_err.c \
				my_getpid.c \
				my_open.c
OBJS	= $(addprefix obj/, $(notdir $(SRCS:.c=.o)))
CFLAGS	+= -Wall -Wextra -ansi -pedantic -lcurses -ggdb
LDFLAGS	+= -L lib/ -lmy

all: lib/libmy.a obj/ $(NAME)

obj/:
	mkdir $@

lib/libmy.a:
	make -C lib/my

$(NAME): $(OBJS)
	gcc -o $@ $(CFLAGS) $(OBJS) $(LDFLAGS)

obj/%.o: src/%.c
	gcc -c $(CFLAGS) -o $@ $< -I include -I lib/my/include

clean:
	make -C lib/my clean
	rm -rf obj/

fclean:
	$(MAKE) -C lib/my fclean
	rm -rf obj/
	rm -rf $(NAME)

re: fclean all
