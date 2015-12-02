/*
** progs_tree.c for minishell1 in /home/cano_c/rendu/UNIX/PSU_2014_minishell1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Jan 19 16:07:07 2015
** Last update Tue Feb  3 11:45:41 2015 
*/
#include <minishell1.h>

t_prog			*find_prog(t_progs *progs, char *progname)
{
  while (*progname)
    {
      if (progs->next[(int)(*progname)])
	progs = progs->next[(int)(*progname)];
      else
	return (NULL);
      ++progname;
    }
  return(progs->prog);
}

static t_progs		*get_prog_place(t_progs *s_progs, char *name)
{
  while (*name)
    {
      if (!s_progs->next[(int)(*name)])
	{
	  if (!(s_progs->next[(int)*name] = my_memalloc(sizeof(*s_progs))))
	    return (NULL);
	}
      s_progs = s_progs->next[(int)*name];
      ++name;
    }
  return (s_progs);
}

char			add_prog(char *filename, char *path, t_progs *s_progs)
{
  size_t		pathlen;
  struct stat		s_stat;
  char			pathname[PATH_MAX + NAME_MAX];

  my_strncpy(pathname, path, PATH_MAX);
  pathlen = my_strlen(path);
  if (pathname[pathlen] != '/')
    pathname[pathlen + 1] = '/';
  pathlen += 1;
  my_strncpy(pathname + pathlen, filename, NAME_MAX);
  if (stat(pathname, &s_stat) != -1)
    {
      if (!(s_progs = get_prog_place(s_progs, filename)))
	return (-1);
      if (!s_progs->prog)
	{
	  if (!(s_progs->prog = my_memalloc(sizeof(*s_progs->prog))))
	    return (-1);
	  s_progs->prog->namlen = my_strlen(filename);
	  my_strncpy(s_progs->prog->name, filename, NAME_MAX);
	  my_strncpy(s_progs->prog->path, path, PATH_MAX);
	}
    }
  return (0);
}

static char		add_dir_progs(char *path, t_progs *s_progs)
{
  DIR			*dir;
  struct dirent		*entry;

  if ((dir = opendir(path)))
    {
      while ((entry = readdir(dir)))
	{
	  if (my_strncmp(entry->d_name, ".", 2)
	      && my_strncmp(entry->d_name, "..", 3))
	    if (add_prog(entry->d_name, path, s_progs) < 0)
	      return (-1);
	}
      closedir(dir);
    }
  else
    return (-1);
  return (0);
}

t_progs			*get_path_progs(char *path)
{
  char			*start;
  char			*end;
  char			endchar;
  char			*pathcpy;
  t_progs		*s_progs;

  if (!path || !*path || !(pathcpy = my_strdup(path)))
    return (NULL);
  start = pathcpy;
  if (!(s_progs = my_memalloc(sizeof(*s_progs))))
    return (NULL);
  while (*start)
    {
      end = start;
      while (*end && *end != ':')
	++end;
      endchar = *end;
      *end = 0;
      if (add_dir_progs(start, s_progs) == -2)
	return (NULL);
      *end = endchar;
      if ((start = end) && *start)
	++start;
    }
  free(pathcpy);
  return (s_progs);
}
