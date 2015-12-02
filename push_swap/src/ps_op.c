/*
** ps_op.c for push_swap in /home/cano_c/rendu/ELEM/CPE_2014_Pushswap
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Dec  4 11:06:30 2014
** Last update Thu Dec  4 11:32:17 2014 
*/

#include <push_swap.h>

void			print_step(void)
{
  t_lst			**l_a;
  t_lst			**l_b;

  l_a = s_la(NULL);
  l_b = s_lb(NULL);
  my_putstr("\033[0m[l_a] ");
  if (*l_a)
    print_lst(*l_a);
  else
    my_putstr("(null)");
  my_putchar('\n');
  my_putstr("\t[l_b] ");
  if (*l_b)
    print_lst(*l_b);
  else
    my_putstr("(null)");
  my_putchar('\n');
}

t_lst			**s_la(t_lst *la)
{
  static t_lst		*l_a = NULL;

  if (la)
    l_a = la;
  return (&l_a);
}

t_lst			**s_lb(t_lst *lb)
{
  static t_lst		*l_b = NULL;

  if (lb)
    l_b = lb;
  return (&l_b);
}

int			sa(int UN op)
{
  int			ret;

  my_putstr("sa ");
  ret = lst_swap(s_la(NULL));
  if (op & O_VERB)
    print_step();
  return (ret);
}

int			sb(int UN op)
{
  int			ret;

  my_putstr("sb ");
  ret = lst_swap(s_lb(NULL));
  if (op & O_VERB)
    print_step();
  return (ret);
}

int			ss(int UN op)
{
  my_putstr("ss ");
  return (sa(op) + sb(op));
}

int			pa(int UN op)
{
  t_lst			*tmp;

  my_putstr("pa ");
  if ((tmp = lst_pop(s_lb(NULL))))
    {
      lst_push(s_la(NULL), tmp);
      if (op & O_VERB)
	print_step();
      return (1);
    }
  if (op & O_VERB)
    print_step();
  return (0);
}

int			pb(int UN op)
{
  t_lst			*tmp;

  my_putstr("pb ");
  if ((tmp = lst_pop(s_la(NULL))))
    {
      lst_push(s_lb(NULL), tmp);
      if (op & O_VERB)
	print_step();
      return (1);
    }
  if (op & O_VERB)
    print_step();
  return (0);
}

int			ra(int UN op)
{
  int			ret;

  my_putstr("ra ");
  ret = lst_rot(s_la(NULL));
  if (op & O_VERB)
    print_step();
  return (ret);
}

int			rb(int UN op)
{
  int			ret;

  my_putstr("rb ");
  ret = lst_rot(s_lb(NULL));
  if (op & O_VERB)
    print_step();
  return (ret);
}

int			rr(int UN op)
{
  int			ret;

  my_putstr("rr ");
  ret = lst_rot(s_lb(NULL));
  ret += lst_rot(s_la(NULL));
  if (op & O_VERB)
    print_step();
  return (ret);
}

int			rra(int UN op)
{
  int			ret;

  my_putstr("rra ");
  ret = lst_rrot(s_la(NULL));
  if (op & O_VERB)
    print_step();
  return (ret);
}

int			rrb(int UN op)
{
  int			ret;

  my_putstr("rrb ");
  ret = lst_rrot(s_lb(NULL));
  if (op & O_VERB)
    print_step();
  return (ret);
}

int			rrr(int UN op)
{
  int			ret;

  my_putstr("rrr");
  ret = lst_rrot(s_lb(NULL));
  ret += lst_rrot(s_la(NULL));
  if (op & O_VERB)
    print_step();
  return (ret);
}
