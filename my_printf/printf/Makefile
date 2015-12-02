##
## Makefile for printf in /home/cano_c/rendu/UNIX/PSU_2014_my_printf/src/printf
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Mon Nov 10 08:59:28 2014
## Last update Sun Nov 16 20:16:33 2014 Cano Chloe
##

PSRC	= format_output.c parse_flags.c parse_str.c printf.c print_va.c \
	get_va.c cast_va.c cast_va_2.c print_ll.c get_ll_len.c print_str.c \
	output_integer.c
POBJ	= $(addprefix obj/, $(notdir $(PSRC:.c=.o)))
CFLAGS	+= -Wall -Wextra -ansi -pedantic -std=c99

all: obj/ $(POBJ)

obj/:
	mkdir obj

obj/%.o: printf/src/%.c
	gcc $(CFLAGS) -c -o $@ $< -I $(INC) -ggdb

pclean:
	rm -rf $(POBJ)

pre: fclean all
