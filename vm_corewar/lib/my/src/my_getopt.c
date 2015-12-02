/*
** my_getopt.c for libmy in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 24 20:04:27 2014
** Last update Fri Apr 10 00:52:22 2015 
*/

#include <my.h>

static void	put_arg_back(char **argv, int op_idx)
{
  int		idx;
  char		mv;
  char		*arg;

  arg = *(argv + op_idx);
  idx = op_idx;
  mv = 0;
  while (idx > 1 && **(argv + idx - 1) == '-')
    {
      *(argv + idx) = *(argv + idx - 1);
      --idx;
      mv = 1;
    }
  if (mv && *(argv + idx) && **(argv + idx) != '-')
    ++idx;
  *(argv + idx) = arg;
}

static int	get_op_idx(char **argv, int op_idx)
{
  op_idx = 0;
  while (*(argv + op_idx) && **(argv + op_idx) != '-')
    ++op_idx;
  while (op_idx > 1 && *(argv + op_idx) && **(argv + op_idx) == '-')
    --op_idx;
  while (*(argv + op_idx) && **(argv + op_idx) != '-')
    ++op_idx;
  if (!*(argv + op_idx) || (op_idx > 0 && **(argv + op_idx) != '-'))
    op_idx = -1;
  return (op_idx);
}

void		set_op(int *op_idx, char **op)
{
  *op = NULL;
  ++(*op_idx);
}

int		my_getopt(char **argv, char *ops, int *op_idx, char ***arg)
{
  static char	*op = NULL;

  set_op(op_idx, &op);
  *arg = NULL;
  while (!op && *(argv + *op_idx))
    {
      while (*(argv + *op_idx) && **(argv + *op_idx) != '-')
	{
	  put_arg_back(argv, *op_idx);
       	  ++(*op_idx);
	}
      op = *(argv + *op_idx);
    }
  if (*(argv + *op_idx))
    *arg = (argv + *op_idx + 1);
  while (op && *ops && *(op + 1) != *ops)
    ++ops;
  if (op && !*(++op))
    op = NULL;
  if (op && *ops)
    return (*(op));
  else if (op)
    return (-2);
  else
    *op_idx = get_op_idx(argv, *op_idx);
  return (-1);
}
