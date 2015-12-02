/*
** get_dir_entries.c for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sat Nov 29 20:59:40 2014
** Last update Sun Nov 30 18:06:33 2014 Cano Chloe
*/

#include <my_ls.h>

int		get_dir_entry(int *len, char *pathname, int opt, t_lst **s_lst)
{
  t_blk		*new;
  int		errsave;
  int		ret;

  errsave = errno;
  if ((new = get_entry(pathname, opt, len)))
    {
      if (opt & O_TIM)
	ret = lst_insert(s_lst, new, &entry_time_cmp);
      else
	ret = lst_insert(s_lst, new, &entry_cmp);
      if (ret < 0)
	{
	  errsave = errno;
	  print_error(pathname, strerror(errno));
	}
      free(new);
    }
  else if (new == (void *)-1)
    {
      errsave = errno;
      print_error(pathname, strerror(errno));
    }
  return (errsave);
}

size_t		set_path_prefix(t_blk *blk, char *pathname)
{
  size_t       	prefix_len;

  prefix_len = my_strlen(ENTRY(blk)->path);
  my_strncpy(pathname, ENTRY(blk)->path, prefix_len);
  pathname[prefix_len] = '/';
  if (ENTRY(blk)->path[prefix_len - 1] == '/')
    --prefix_len;
  return (prefix_len);
}

size_t		set_path_suffix(char *pathname, struct dirent *dire,
				size_t prefix_len)
{
  size_t	suffix_len;

  suffix_len = my_strlen(dire->d_name);
  my_strncpy(pathname + prefix_len + 1, dire->d_name,
	     PATH_MAX - prefix_len - 1);
  return (suffix_len);
}

t_lst		*get_dir_entries(t_blk *blk, t_lst **s_lst, int opt, int *len)
{
  DIR		*dir;
  struct dirent	*dire;
  int		errsave;
  size_t	path_len[2];
  char		pathname[PATH_MAX];

  path_len[0] = set_path_prefix(blk, pathname);
  if ((dir = opendir(ENTRY(blk)->path)))
    {
      errsave = errno;
      while ((dire = readdir(dir)))
	{
	  path_len[1] = set_path_suffix(pathname, dire, path_len[0]);
	  if (path_len[1] + path_len[0] + 2 <= PATH_MAX)
	    {
	      *(pathname + path_len[0] + path_len[1] + 2) = 0;
	      errsave = get_dir_entry(len, pathname, opt, s_lst);
	    }
	}
      closedir(dir);
    }
  if (errno != errsave || !dir)
    print_error(ENTRY(blk)->path, strerror(errno));
  return (*s_lst);
}
