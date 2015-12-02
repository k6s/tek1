/*
** main.c for minishell1 in /home/cano_c/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Jan 13 13:47:28 2015
** Last update Fri Jan 30 20:27:07 2015 
*/
#include <minishell1.h>

int			init_mysh(t_term *s_term, char **environ)
{
  char			*env_path;

  my_bzero((void *)s_term, sizeof(*s_term));
  if (environ && *environ)
    {
      if (!(get_environ(s_term, environ)))
	{
	  static_term(s_term);
	  init_signals();
	  if (!(s_term->tsave = init_termcap(s_term->environ)))
	    return (-1);
	  s_term->pid = my_getpid();
	  s_term->progs = NULL;
	  if ((env_path = my_getenv(environ, "PATH="))
	      && (s_term->progs = get_path_progs(env_path))
	      && !add_builtins(s_term->progs))
	    return (0);
	}
    }
  else
    errno = E_ENV;
  return (-1);
}

static int		init_io(char *tty_name)
{
  int			fd;

  close(0);
  close(1);
  if ((fd = my_open(tty_name, O_RDONLY)) == -1)
    my_perror(errno, "mysh", tty_name);
  if ((fd = my_open(tty_name, O_WRONLY)) == -1)
    my_perror(errno, "mysh", tty_name);
  return (fd);
}

int			main(int UN argc, char UN **argv, char **environ)
{
  t_term		s_term;
  int			ret;

  ret = -1;
  errno = 0;
  if (init_io("/dev/tty") == -1)
    return (-2);
  if (!init_mysh(&s_term, environ))
    {
      ret = shell_readloop(&s_term);
      free_stuff(&s_term);
      restore_termcap(s_term.tsave);
      free(s_term.tsave);
    }
  else
    {
      my_perror(errno, "mysh", NULL);
      return (-2);
    }
  return (ret);
}
