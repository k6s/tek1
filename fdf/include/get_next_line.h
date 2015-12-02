/*
** get_next_line.h for get_next_line in ~/rendu/ELEM/CPE_2014_get_next_line
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 17 11:13:18 2014
** Last update Sun Nov 23 23:21:11 2014 Cano Chloe
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/types.h>

# define READ_LEN		10
# define EOL			'\n'

typedef struct s_blk		t_blk;
typedef struct s_lst		t_lst;

char		*get_next_line(const int fd);

struct		s_blk
{
  char		data[READ_LEN];
  size_t	len;
};

struct		s_lst
{
  t_blk		blk;
  t_lst		*next;
};

t_lst		**get_fd_tab(const int fd);
t_lst		*lst_memchr(t_lst *haystack, char needle, ptrdiff_t *off);
void		next_elem(t_lst **lst, t_lst *new, t_lst **tmp);

#endif /* !GET_NEXT_LINE_H_ */
