/*
** sh_exe.c for minishell1 in /home/cano_c/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Jan 25 03:24:19 2015
** Last update Sun Feb  1 22:37:29 2015 
*/
#include <minishell1.h>

char    		exe_builtin(t_prog *prog, char **av, t_term *s_term)
{
  char  ret;

  ret = (*prog->builtfp)(s_term, av);
  free_strtab(av);
  return ((char)ret);
}

t_term			*static_term(t_term *term)
{
  static t_term		*s_term = NULL;

  if (term)
    s_term = term;
  return (s_term);
}

char    		exe_cmd(t_prog *s_prog, char **av, char **environ)
{
  size_t		pathlen;
  char			pathname[NAME_MAX + PATH_MAX];
  pid_t			pid;
  int			status;

  pathlen = my_strlen(s_prog->path);
  my_strncpy(pathname, s_prog->path, PATH_MAX);
  if (pathname[pathlen] != '/')
    pathname[(pathlen++)] = '/';
  my_strncpy(pathname + pathlen, s_prog->name, NAME_MAX);
  pathname[NAME_MAX + PATH_MAX - 1] = 0;
  if ((pid = my_fork()) > -1)
    {
      if (!pid)
	  my_execve(pathname, av, environ);
      else
	{
	  waitpid(pid, &status, 0);
	  free_strtab(av);
	  return (WEXITSTATUS(status));
	}
    }
  free_strtab(av);
  return (-2);
}
