/*
** print_mode.c for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sat Nov 29 21:40:29 2014
** Last update Sun Nov 30 17:21:02 2014 Cano Chloe
*/

#include <my_ls.h>

void			print_type(mode_t *st_mode)
{
  if (S_ISDIR(*st_mode))
    my_putchar('d');
  else if (S_ISREG(*st_mode))
    my_putchar('-');
  else if (S_ISCHR(*st_mode))
    my_putchar('c');
  else if (S_ISBLK(*st_mode))
    my_putchar('b');
  else if (S_ISFIFO(*st_mode))
    my_putchar('p');
  else if (S_ISLNK(*st_mode))
    my_putchar('l');
#if LONG_ETYPE
  else if (S_ISSOCK(*st_mode))
    my_putchar('s');
#endif
  else
    my_putchar('?');
}

static void		print_perm(int isset, char p)
{
  if (isset)
    my_putchar(p);
  else
    my_putchar('-');
}

void			print_perms(mode_t *st_mode)
{
  print_perm(S_IRUSR & *st_mode, 'r');
  print_perm(S_IWUSR & *st_mode, 'w');
  if (S_ISUID & *st_mode)
    my_putchar('s');
  else
    print_perm(S_IXUSR & *st_mode, 'x');
  print_perm(S_IRGRP & *st_mode, 'r');
  print_perm(S_IWGRP & *st_mode, 'w');
  if (S_ISGID & *st_mode)
    my_putchar('s');
  else
    print_perm(S_IXGRP & *st_mode, 'x');
  print_perm(S_IROTH & *st_mode, 'r');
  print_perm(S_IWOTH & *st_mode, 'w');
  if (__S_ISVTX & *st_mode)
    my_putchar('t');
  else
    print_perm(S_IXOTH & *st_mode, 'x');
}
