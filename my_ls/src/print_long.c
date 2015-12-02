/*
** print_long.c for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Nov 26 22:50:20 2014
** Last update Sun Nov 30 18:07:14 2014 Cano Chloe
*/

#include <my_ls.h>

static void		print_time(time_t *st_mtime)
{
  char			*mtime;
  time_t		s_time;

  mtime = ctime(st_mtime);
  if ((s_time = time(NULL)) > (time_t)-1)
    {
      mtime += 4;
      if (s_time - *st_mtime >= 31556926)
	{
	  write(1, mtime, 6);
	  while (*(mtime + 5) != '\n')
	    ++mtime;
	  my_putchar(' ');
	  write(1, mtime, 5);
	}
      else
	{
	  while (*(mtime + 8) != '\n')
	    my_putchar(*mtime++);
	}
    }
  else
      write(1, "          ? ", 12);
}

void	do_padding(ssize_t space_len)
{
  if (space_len > 0)
    {
      while (space_len--)
	write(1, " ", 1);
    }
}

void	print_logins(t_blk *blk, int *padding)
{
  if (ENTRY(blk)->pwd[0])
    my_putstr(ENTRY(blk)->pwd);
  else
    my_put_nbr(ENTRY(blk)->stat.st_uid);
  do_padding(padding[1] - ENTRY(blk)->len[1] + 1);
  if (ENTRY(blk)->grp)
    my_putstr(ENTRY(blk)->grp);
  else
    my_put_nbr(ENTRY(blk)->stat.st_gid);
  do_padding(padding[2] - ENTRY(blk)->len[2]);
}

void		print_size(t_blk *blk, int *padding)
{
  if (S_ISBLK(ENTRY(blk)->stat.st_mode) || S_ISCHR(ENTRY(blk)->stat.st_mode))
    {
      do_padding(padding[3] - ENTRY(blk)->len[3]);
      my_put_nbr(MAJOR(ENTRY(blk)->stat.st_rdev));
      my_putstr(", ");
      do_padding(padding[4] - ENTRY(blk)->len[4]);
      my_put_nbr(MINOR(ENTRY(blk)->stat.st_rdev));
    }
  else
    {
      if (padding[4])
	do_padding(padding[3] + padding[4] - ENTRY(blk)->len[3] + 2);
      else
	do_padding(padding[3] - ENTRY(blk)->len[3] + 1);
      my_put_nbr(ENTRY(blk)->stat.st_size);
    }
}

void	print_long(t_blk *blk, int *padding)
{
  print_type(&ENTRY(blk)->stat.st_mode);
  print_perms(&ENTRY(blk)->stat.st_mode);
  do_padding(padding[0] - ENTRY(blk)->len[0] + 1);
  my_put_nbr(ENTRY(blk)->stat.st_nlink);
  my_putchar(' ');
  print_logins(blk, padding);
  print_size(blk, padding);
  my_putchar(' ');
  print_time(&ENTRY(blk)->stat.st_mtime);
  my_putchar(' ');
}
