/*
** get_next_line.h for get_next_line in ~/rendu/ELEM/CPE_2014_get_next_line
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 17 11:13:18 2014
** Last update Tue Nov 18 15:59:47 2014 
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>
# include <stddef.h>

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

#endif /* !GET_NEXT_LINE_H_ */
