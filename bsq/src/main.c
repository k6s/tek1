/*
** main.c for bsq in /home/cano_c/rendu/ELEM/CPE_2014_bsq
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Dec 22 20:02:31 2014
** Last update Mon Jan 12 15:04:24 2015 
*/
#include <bsq.h>

int		main(int argc, char **argv)
{
  t_map		*s_map;
  t_square	*s_square;

  if (argc == 2)
    {
      if ((s_map = read_map(argv[1])))
	{
	  if (!(s_square = find_square(s_map)))
	    return (-1);
	  print_map(s_map, s_square);
	}
      else
	return (-1);
      free(s_map->map);
      free(s_map);
      free(s_square);
    }
  else
    my_putstr("usage: ./bsq map\n");
  return (0);
}
