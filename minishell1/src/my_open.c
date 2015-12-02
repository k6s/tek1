/*
** my_open.c for minishell.h in /home/cano_c/rendu/UNIX/my_select/minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Jan 30 18:13:52 2015
** Last update Sat Jan 31 01:05:51 2015 
*/
#include <minishell1.h>

pid_t		my_fork(void)
{
  pid_t		pid;

  if ((pid = fork()) < 0)
    errno = E_FORK;
  return (pid);
}

void		my_execve(char *pathname, char **av, char **environ)
{
  execve(pathname, av, environ);
  write(2, "Command failed to execute properly\n", 25);
  exit(EXIT_FAILURE);
}

int		my_access(const char *path, int flag)
{
  if (access(path, flag))
    {
      if (my_strlen(path) > PATH_MAX)
	errno = E_NAMETOOLNG;
      else
	{
	  if (flag == F_OK)
	    errno = E_NSFD;
	  else if (flag == R_OK || flag == R_OK || flag == X_OK)
	    errno = E_PERM;
	}
      return (-1);
    }
  return (0);
}

DIR		*my_opendir(const char *name)
{
  DIR		*dir;
  struct stat	s_stat;

  if (!(dir = opendir(name)))
    {
      if (my_access(name, F_OK) || my_access(name, R_OK))
	return (dir);
      else if (!stat(name, &s_stat) && !(S_ISDIR(s_stat.st_mode)))
	errno = E_NOTDIR;
      else
	errno = E_OPENDIR;
    }
  return (dir);
}

int		my_open(char *path, int flags)
{
  int		fd;

  if ((fd = open(path, flags)) == -1)
    {
      if (my_access(path, F_OK))
	return (fd);
      else if ((flags & O_RDONLY || flags & O_RDWR)
	       && (my_access(path, R_OK)))
	return (fd);
      else if ((flags & O_WRONLY || flags & O_RDWR)
	       && (my_access(path, W_OK)))
	return (fd);
      else
	errno = E_OPEN;
    }
  return (fd);
}
