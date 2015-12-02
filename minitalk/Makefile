##
## Makefile for minitalk in /home/k6/epitech/UNIX/minitalk
## 
## Made by Chloe Cano
## Login   <cano_c@epitech.net>
## 
## Started on  Fri Feb 20 14:43:11 2015
## Last update Mon Mar 16 12:32:22 2015 
##
SERVER	= server
CLIENT	= client
S_SRC = server.c new_client.c receive_msg.c
C_SRC = client.c send_str.c send_pid.c kill_serv.c
S_OBJ = $(addprefix obj/, $(notdir $(S_SRC:.c=.o)))
C_OBJ = $(addprefix obj/, $(notdir $(C_SRC:.c=.o)))
CFLAGS += -Wall -Wextra

all: obj/ lib/libmy.a $(SERVER) $(CLIENT)

obj/:
	mkdir $@

lib/libmy.a:
	make -C lib/my

$(SERVER): $(S_OBJ)
	gcc $(CFLAGS) -o $@ $(S_OBJ) -L lib -lmy

$(CLIENT): $(C_OBJ)
	gcc $(CFLAGS) -o $@ $(C_OBJ) -L lib -lmy

obj/%.o: src/%.c
	gcc -c $(CFLAGS) -c -o $@ $< -I include -I lib/my/include

clean:
	rm -rf $(S_OBJ) $(C_OBJ)
	make -C lib/my clean

fclean: clean
	rm -rf $(NAME)
	make -C lib/my fclean

re: fclean all
	make -C lib/my re
