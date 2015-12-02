/*
** my_cd.c for minishell1 in /home/cano_c/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Jan 19 16:31:10 2015
** Last update Sun Feb  1 23:13:33 2015 
*/
#include <minishell1.h>

void		cat_envvar(char *var, char *varname, char *value)
{
  my_strncpy(var, varname, my_strlen(varname) + 1);
  my_strcat(var, "=");
  if (value)
    my_strcat(var, value);
}

int		my_cd(t_term *s_term, char **av)
{
  char		pwd[PATH_MAX + 10];
  char		cwd[PATH_MAX];

  if (av[1] && (my_access(av[1], R_OK) || my_access(av[1], F_OK)))
    {
      my_perror(errno, "cd", av[1]);
      return (-1);
    }
  if (av[1] && !my_strncmp(av[1], "PWD=/", 2) && !chdir(av[1]))
      return (0);
  else if (!chdir(av[1]))
      return (0);
  else
    my_perror(errno, "cannot cd to", av[1]);
  return (-1);
}
