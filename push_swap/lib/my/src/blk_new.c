/*
** blk_new.c for lib in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Nov 27 01:32:54 2014
** Last update Thu Nov 27 01:33:09 2014 
*/

#include <my.h>

t_blk		*blk_new(size_t data_len)
{
  t_blk		*blk;

  if ((blk = malloc(sizeof(*blk))))
    {
      blk->len = 0;
      if (data_len)
	{
	  if (!(blk->data = malloc(data_len)))
	    {
	      free(blk);
	      blk = NULL;
	    }
	  else
	    blk->len = data_len;
	}
      else
	blk->data = NULL;
    }
  return (blk);
}
