/*
** main.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique/src
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov  9 12:35:50 2014
** Last update Sun Nov  9 17:43:51 2014 Cano Chloe
*/

#include <eval_expr.h>

static void	usage(void)
{
  my_putstr("./calc base ops exp_len\n");
}

int		get_str_len(char *str, int size_read)
{
  int		idx;

  idx = 0;
  while (idx < size_read && str[idx] != '\n')
    ++idx;
  *(str + idx) = 0;
  return (idx);
}

char		*read_expr(char *av, int *size_read)
{
  char		*str;

  str = NULL;
  if ((*size_read = my_getnbr(av)) < 1)
    usage();
  else if ((str = malloc(sizeof(*str) * *size_read + 1)))
    {
      if ((read(0, str, *size_read)) != *size_read || *str == '\n')
	{
	  if (*size_read < 0)
	    my_putstr("Read failed.\n");
	  else
	    usage();
	  free(str);
	  str = NULL;
	}
      else
	*size_read = get_str_len(str, *size_read);
    }
  else
    my_putstr("Malloc Failed. Deal with it...\n");
  return (str);
}

int		main(int ac, char **av)
{
  char		*str;
  int		len[2];
  t_nb		*res;

  if (ac == 4)
    {
      if ((len[0] = is_valid(av[1], av[2])) < 2)
	return (0);
      if ((str = read_expr(av[3], &len[1])))
	{
	  res = evalexpr(str, av[1], av[2], len);
	  if (res)
	    my_putstr(res->nb);
	  free(str);
	}
    }
  else
    usage();
  return (0);
}
