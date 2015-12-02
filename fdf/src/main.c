/*
** fdf.c for fdf in /home/cano_c/rendu/IGRAPH/MLU_2014_fdf
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Nov 18 16:49:25 2014
** Last update Sun Nov 23 20:08:32 2014 
*/

#include <fdf.h>

void		usage(void)
{
  my_putstr("./fdf map\n");
}

int		main(int argc, char **argv)
{
  t_fdf      	s_fdf;
  int		fd;

  if (argc == 2)
    {
      s_fdf.len[0] = 0;
      s_fdf.len[1] = 0;
      if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
	  perror(argv[1]);
	  return (-1);
	}
      if (!(s_fdf.map = get_map(fd, 0, &s_fdf)))
	return (0);
      fdf(&s_fdf);
      free_map(s_fdf.map);
      close(fd);
    }
  else
    usage();
  return (0);
}
