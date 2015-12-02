/*
** is_valid.c for Bistro in /home/cano_c/rendu/ELEM/Bistromatique
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Oct 30 18:52:34 2014
** Last update Sun Nov  9 17:27:12 2014 Cano Chloe
*/
#include <eval_expr.h>

static int	check_ops(char *ops, char *dup)
{
  int		nb_ops;

  nb_ops = 0;
  while (ops[nb_ops])
    {
      if (dup[(int)ops[nb_ops]])
	{
	  my_putstr("mount /dev/brain, then try again\n");
	  return (-1);
	}
      dup[(int)ops[nb_ops]] = 1;
      ++nb_ops;
    }
  if (nb_ops != 7)
    my_putstr("There MUST be EXACTLY 7 operators\n");
  return (nb_ops);
}

static int	check_base(char *base, char *dup)
{
  int		base_len;

  base_len = 0;
  while (base[base_len])
    {
      if (dup[(int)base[base_len]])
	return (0);
      dup[(int)base[base_len]] = 1;
      ++base_len;
    }
  if (base_len < 2)
    {
      my_putstr("There MUST be at least two characters in the base string\n");
      return (1);
    }
  return (base_len);
}

int		is_valid(char *base, char *ops)
{
  int		base_len;
  char		dup[256];

  my_bzero(dup, 256);
  if ((base_len = check_base(base, dup)) < 2)
    {
      if (!base_len)
	{
	  my_putstr("Providing twice the same character in the base string is \
nonsense.\n");
	  return (0);
	}
    }
  if ((check_ops(ops, dup)) != 7)
    return (0);
  return (base_len);
}
