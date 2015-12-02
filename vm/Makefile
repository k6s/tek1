##
## Makefile for corewar in /home/cano_c/rendu/ELEM/corewar
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Wed Mar 18 17:22:52 2015
## Last update Fri Apr 10 18:23:14 2015 Stéphane
##
NAME	=	vm
SRC	=	main.c \
		get_file.c \
		get_players.c \
		proc.c \
		lst.c \
		regs.c \
		op.c \
		args_utils.c \
		args_addr.c \
		args_lld.c \
		inst_utils.c \
		inst_add.c \
		inst_sti.c \
		inst_zjmp.c \
		inst_live.c \
		inst_and.c \
		inst_st.c \
		inst_ld.c \
		inst_lld.c \
		inst_lldi.c \
		inst_aff.c \
		endian.c \
		curses.c curses_update.c
OBJ	=	$(addprefix obj/, $(notdir $(SRC:.c=.o)))
CFLAGS	+=	-Wall -Wextra
LDFLAGS	=	-Llib/ -lmy -lm -lcurses

all: obj/ $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

obj/:
	mkdir $@

obj/%.o: src/%.c
	gcc $(CFLAGS) -c -o $@ $< -I include -I lib/my/include -ggdb

clean:
	make -C lib/my clean
	rm -rf obj/

fclean: clean
	make -C lib/my fclean
	rm -rf $(NAME)

re: fclean all
