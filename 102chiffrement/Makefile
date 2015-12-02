##
## Makefile for 102chiffrement in /home/cano_c/rendu/MATHS/102chiffrement
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Sun Nov 30 22:41:52 2014
## Last update Sun Nov 30 22:51:27 2014 
##

NAME	= 102chiffrement
SRC	= 102chiffrement.c
OBJ	= 102chiffrement.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $@ $<

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
