/*
** color_op.c for rtv1 in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 23 13:32:00 2015
** Last update Sun Mar 15 16:13:33 2015 Cano Chloe
*/
#include <graph.h>

long		color_add(long color, long to_add)
{
  long		new;

  new =  0x000000ff & ((color & 0x000000ff) + (to_add & 0x000000ff));
  new |= 0x0000ff00 & ((color & 0x0000ff00) + (to_add & 0x0000ff00));
  new |= 0x00ff0000 & ((color & 0x00ff0000) + (to_add & 0x00ff0000));
  new |= 0xff000000 & ((color & 0xff000000) + (to_add & 0xff000000));
  return (new);
}

long		color_sub(long color, long to_add)
{
  long		new;

  new =  0x000000ff & ((color & 0x000000ff) - (to_add & 0x000000ff));
  new |= 0x0000ff00 & ((color & 0x0000ff00) - (to_add & 0x0000ff00));
  new |= 0x00ff0000 & ((color & 0x00ff0000) - (to_add & 0x00ff0000));
  new |= 0xff000000 & ((color & 0xff000000) - (to_add & 0xff000000));
  return (new);
}

long		color_mul(long color, long to_add)
{
  long		new;

  new =  0x000000ff & ((color & 0x000000ff) * (to_add & 0x000000ff));
  new |= 0x0000ff00 & ((color & 0x0000ff00) * (to_add & 0x0000ff00));
  new |= 0x00ff0000 & ((color & 0x00ff0000) * (to_add & 0x00ff0000));
  new |= 0xff000000 & ((color & 0xff000000) * (to_add & 0xff000000));
  return (new);
}
