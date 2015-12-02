/*
1;2802;0c** bsq.h for bsq in /home/cano_c/rendu/ELEM/CPE_2014_bsq
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Dec 24 14:51:54 2014
** Last update Sun Jan 18 21:07:09 2015 
*/

#ifndef BSQ_H_
# define BSQ_H_

# include <my.h>
# include <get_next_line.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define CASE(s_map, li, co)    (s_map->map[(li) * s_map->sizeline + (co) / 8])
# define MAP_VAL(s_map, li, co) (CASE(s_map, li, co) >> (co) % 8 & 1)

typedef struct s_map	t_map;
typedef struct s_square t_square;

struct		s_map
{
  char		*map;
  size_t	li;
  size_t	co;
  size_t	sizeline;
};

struct		s_square
{
  size_t        li;
  size_t        co;
  size_t        size;
};

/*
** output.c
*/
void		print_map(t_map *s_map, t_square *s_square);
t_map		*map_error(t_map *s_map, int fd, char *msg);
t_square	*square_error(t_map *s_map, t_square *s_square, char *msg);

/*
** read_map.c
** Return a filled s_map struct based on the file whose path
** is given as first arg, or NULL if path / file is not valid.
*/
t_map		*read_map(char *path);

/*
** square.c
** fill a square struct with the coordinates (high/left) and size of the biggest
** empty square in map.
** returns this square struct if at least one square can be drawn,
** (1x1 square is valid), or NULL if there is no empty spqce in the map.
*/
t_square    *find_square(t_map *s_map);

#endif /* !BSQ_H_ */
