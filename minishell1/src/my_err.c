/*
** my_err.c for minishell1 in /home/cano_c/rendu/UNIX/my_select/minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Jan 30 17:49:54 2015
** Last update Fri Jan 30 20:55:14 2015 
*/
#include <minishell1.h>

static char	*my_strerr(void)
{
  static char	strerr[(MAX_ERRNO + 1) * MAX_ERRMSG] = {0};

  if (!*strerr)
    {
      SET_ERRSTR(strerr, E_SUCCESS, "Success");
      SET_ERRSTR(strerr, E_OOM, "Out of memory");
      SET_ERRSTR(strerr, E_NSFD, "No such file or directory");
      SET_ERRSTR(strerr, E_FILENF, "File not found");
      SET_ERRSTR(strerr, E_DIRNF, "Directory not found");
      SET_ERRSTR(strerr, E_NAMETOOLNG, "Name too long");
      SET_ERRSTR(strerr, E_PERM, "Permission denied");
      SET_ERRSTR(strerr, E_OPEN, "Cannot open file");
      SET_ERRSTR(strerr, E_OPENDIR, "Cannot open directory");
      SET_ERRSTR(strerr, E_NOTDIR, "Is not a directory");
      SET_ERRSTR(strerr, E_TERMCAP, "Cannot initialize termcap");
      SET_ERRSTR(strerr, E_ENV, "Null environment / no such variable in env");
      SET_ERRSTR(strerr, E_FORK, "Cannot fork process");
    }
  return (strerr);
}

void		my_perror(int my_errno, char *prog_name, char *msg)
{
  char		*strerr;

  strerr = my_strerr();
  if (prog_name)
    {
      write(2, prog_name, my_strlen(prog_name));
      write(2, ": ", 2);
    }
  if (msg)
    {
      write(2, msg, my_strlen(msg));
      write(2, ": ", 2);
    }
  write(2, &(strerr[ABS(my_errno) * MAX_ERRMSG]), MAX_ERRMSG);
  write(2, "\n", 1);
}
