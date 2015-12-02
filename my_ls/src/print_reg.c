/*
** print_reg.c for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sat Nov 29 22:23:09 2014
** Last update Sun Nov 30 18:37:13 2014 Cano Chloe
*/

#include <my_ls.h>

void		print_error(char *msg, char *err_msg)
{
  my_putstr_fd("ls: ", 2);
  if (msg)
    {
      my_putstr_fd(msg, 2);
      my_putstr_fd(": ", 2);
    }
  my_putstr_fd(err_msg, 2);
  write(1, "\n", 2);
}

void		print_total(int *total)
{
  if (*total > -1)
    {
      my_putstr("total ");
      my_put_nbr(*total);
      my_putchar('\n');
      *total = -1;
    }
}

void		print_entry(t_blk *blk, int opt, int *len)
{
  size_t	idx;

  idx = get_filename_idx(ENTRY(blk)->path);
  if (ENTRY(blk)->path[idx] != '.' || opt & O_ALL || opt & O_DIR)
    {
      if (ENTRY(blk)->error)
	print_error(ENTRY(blk)->path, ENTRY(blk)->error);
      else
	{
	  if (opt & O_LNG)
	    {
	      print_total(&len[5]);
	      print_long(blk, len);
	    }
	  if (ENTRY(blk)->lnk[0])
	    print_lnk(blk);
	  else
	    my_putstr(ENTRY(blk)->path + idx);
	  my_putchar('\n');
	}
    }
}
