/*
** push_swap.c for push_swap in /home/cano_c/rendu/ELEM/CPE_2014_Pushswap/lib/my** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Dec  1 18:46:57 2014
** Last update Thu Dec  4 11:04:52 2014 
*/

#include <push_swap.h>

void		usage(void)
{
  my_putstr("usage: ./push_swap n1 n2 n3 ...\n");
}

void		error(void)
{
  my_putstr_fd("error\n", 2);
  exit(2);
}

t_lst		*get_lst(char **argv, int first_op)
{
  t_lst		*l_a;
  t_lst		*new;
  int		*data;
  char		**arg;

  l_a = NULL;
  arg = argv;
  while (argv - arg < first_op - 1)
    {
      new = NULL;
      if (is_nbr(*argv))
	{
	  if ((data = malloc(sizeof(*data))))
	    {
	      *data = my_getnbr(*argv);
	      if ((new = lst_new_data(data, sizeof(int))))
		lst_push(&l_a, new);
	    }
	}
      if (!new)
	{
	  lst_sclear(&l_a);
	  return (NULL);
	}
      ++argv;
    }
  return (l_a);
}

void		print_lst(t_lst *lst)
{
  while (lst)
    {
      my_put_nbr(*(int *)(lst->blk.data));
      my_putchar(' ');
      lst = lst->prev;
    }
  my_putchar('\n');
}

size_t		lst_slen(t_lst *lst)
{
  t_lst		*plst;
  size_t	len;

  plst = lst;
  len = 0;
  while (plst)
    {
      plst = plst->prev;
      if (plst == lst)
	plst = NULL;
      else
	++len;
    }
  return (len);
}

t_lst		*push_swap(t_lst *l_a, int op)
{
  size_t	nb_elem;
  t_lst		**p;

  s_la(l_a);
  nb_elem = lst_slen(l_a);
  quicksort(0, nb_elem - 1, op);
  lst_sclear(&l_a);
  return (NULL);
}

void		set_op(char c, int *op)
{
  if (c == 'v')
    *op |= O_VERB;
}

int		main(int argc, char **argv)
{
  t_lst		*l_a;
  t_lst		*l_b;
  int		op;
  char		c;
  int		first_op;

  if (argc > 1)
    {
      op = 0;
      first_op = -1;
      while ((c = my_getopt(argv, "v", &first_op)) > 0)
	set_op(c, &op);
      if (first_op < 0)
	first_op = argc;
      if ((l_a = get_lst(argv + 1, first_op)))
	l_b = push_swap(l_a, op);
      else
	  error();
      my_putchar('\n');
    }
  else
    usage();
  return (0);
}
