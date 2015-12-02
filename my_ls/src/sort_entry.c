/*
** sort_entry.c for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov 30 13:29:37 2014
** Last update Sun Nov 30 18:14:29 2014 Cano Chloe
*/

#include <my_ls.h>

int		entry_cmp(t_blk *e1, t_blk *e2, size_t UN len)
{
  return (my_stracmp(ENTRY(e1)->path, ENTRY(e2)->path));
}

int		entry_time_cmp(t_blk *e1, t_blk *e2, size_t UN len)
{
  if (ENTRY(e1)->stat.st_mtime < ENTRY(e2)->stat.st_mtime)
    return (1);
  else if (ENTRY(e1)->stat.st_mtime > ENTRY(e2)->stat.st_mtime)
    return (-1);
  return (my_stracmp(ENTRY(e1)->path, ENTRY(e2)->path));
}
