/*
** get_entry.c for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Nov 26 22:44:50 2014
** Last update Sun Nov 30 18:34:46 2014 Cano Chloe
*/

#include <my_ls.h>

static int	insert_entry(t_lst **lst, t_blk *blk, int opt, char *argv)
{
  int		ret;

  if (opt & O_TIM)
    ret = lst_insert(lst, blk, &entry_time_cmp);
  else
    ret = lst_insert(lst, blk, &entry_cmp);
  if (ret < 0)
    print_error(argv, strerror(errno));
  return (ret);
}

int		get_args_entries(int opt_idx, int opt, t_lst **lst,
				 char **argv)
{
  int		idx;
  t_blk		*blk;
  int		len[6];
  int		nb_files;

  idx = 0;
  nb_files = 0;
  my_bzero(len, 6 * sizeof(len[0]));
  while (++idx < opt_idx)
    {
      if ((blk = get_entry(argv[idx], opt | O_ARG, len)))
	{
	  if (insert_entry(lst, blk, opt, argv[idx]) > 0)
	    ++nb_files;
	  free(blk);
	}
      else if (blk == (void *)-1)
	{
	  print_error(argv[idx], strerror(errno));
	  exit(2);
	}
    }
  return (nb_files > 0 ? nb_files - 1 : 0);
}

static void	get_entry_long(t_blk *blk, char *path, int *padding)
{
  ssize_t      	lnk_len;

  if (lstat(path, &ENTRY(blk)->stat) == -1)
    ENTRY(blk)->error = strerror(errno);
  else
    ENTRY(blk)->error = NULL;
  if (S_ISLNK(ENTRY(blk)->stat.st_mode))
    {
      if ((lnk_len = readlink(path, ENTRY(blk)->lnk, PATH_MAX - 1)) > -1)
	ENTRY(blk)->lnk[lnk_len] = 0;
      else
	ENTRY(blk)->error = strerror(errno);
    }
  if (!ENTRY(blk)->error)
    {
      get_long(blk);
      get_padding(blk, padding);
    }
}

static void	get_entry_reg(t_blk *blk, char *path)
{
  ENTRY(blk)->lnk[0] = 0;
  if (lstat(path, &ENTRY(blk)->stat) == -1)
    ENTRY(blk)->error = strerror(errno);
  else
    ENTRY(blk)->error = NULL;
}

t_blk		*get_entry(char *path, int opt, int *padding)
{
  t_blk		*blk;
  char		*s;
  int		idx;

  blk = NULL;
  idx = get_filename_idx(path);
  if (path[idx] != '.' || opt & O_ALL || opt & O_ARG || opt & O_DIR)
    {
      if ((blk = blk_new(sizeof(struct s_ls_entry))))
	{
	  ENTRY(blk)->len[4] = 0;
	  ENTRY(blk)->lnk[0] = 0;
	  if (opt & O_LNG)
	    get_entry_long(blk, path, padding);
	  else
	    get_entry_reg(blk, path);
	  s = path;
	  while (*s)
	    ENTRY(blk)->path[s - path] = *(s++);
	  ENTRY(blk)->path[s - path] = 0;
	}
      else
	blk = (void *)-1;
    }
  return (blk);
}
