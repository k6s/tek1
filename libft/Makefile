NAME = libft.a
OP = -I ../include
INCLUDES = -I include $(OP) $(LIBFT)
SRCPATH	= srcs/
OBJPATH	= objs/
SRCS = ft_memchr.c ft_memcpy.c ft_memdup.c\
	   puthex_len.c \
	   blk_new.c blk_search.c blk_tok.c blk_dup.c \
	   lbuff_new_elem.c lbuff_push_back.c \
	   class_file.c class_elf.c file_content.c \
	   class_sock.c
SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJ = $(patsubst $(SRCPATH)%.c, $(OBJPATH)%.o, $(SRC))

CFLAGS += -W -Wall -Wextra -Werror $(INCLUDES) -ggdb3

CC = gcc

all: $(NAME)

$(OBJ): | $(OBJPATH) 

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJPATH):
	mkdir -p $(OBJPATH)

clean:
	rm -rf $(OBJPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJPATH)%.o: $(SRCPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re dir
