/*
** builtins_tree.c for minishell1.h in ~/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Jan 19 16:20:40 2015 
** Last update Mon Jan 19 17:05:31 2015 
*/
#include <minishell1.h>

static char		add_builtin(t_progs *progs, char *filename,
				    t_builtfp fp)
{
  char			*pname;

  pname = filename;
  while (*filename)
    {
      if (!progs->next[(int)(*filename)])
	if (!(progs->next[(int)(*filename)] = my_memalloc(sizeof(*progs))))
	  return (-1);
      progs = progs->next[(int)(*filename)];
      ++filename;
    }
  free(progs->prog);
  if (!(progs->prog = my_memalloc(sizeof(t_prog))))
    return (-1);
  progs->prog->namlen = my_strlen(pname);
  my_strncpy(progs->prog->name, pname, NAME_MAX);
  progs->prog->builtfp = fp;
  return (0);
}

char			add_builtins(t_progs *progs)
{
  if (add_builtin(progs, "env", &my_env) == -1)
    return (-1);
  if (add_builtin(progs, "setenv", &my_setenvi) == -1)
    return (-1);
  if (add_builtin(progs, "unsetenv", &my_unsetenv) == -1)
    return (-1);
  if (add_builtin(progs, "cd", &my_cd) == -1)
    return (-1);
  if (add_builtin(progs, "exit", &my_exit) == -1)
      return (-1);
  return (0);
}
