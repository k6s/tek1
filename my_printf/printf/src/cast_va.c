/*
** cast_va.c for printf in /home/cano_c/rendu/UNIX/PSU_2014_my_printf/printf/src
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 10 10:43:09 2014
** Last update Sun Nov 16 20:22:44 2014 Cano Chloe
*/

#include <my.h>

char		cast_char_short(t_types *var, char len[2])
{
  if (len[2] == 'h')
    {
      if ((var->lls = (char)var->lls) < 0)
	return (1);
      return (0);
    }
  else
    if ((var->lls = (short)var->lls) < 0)
      return (1);
  return (0);
}

char		cast_long_llong(t_types *var, char len[2])
{
  if (len[2] == 'l')
    {
      if (var->lls < 0)
	return (1);
      return (0);
    }
  else
    if ((var->lls = (long)var->lls) < 0)
      return (1);
  return (0);
}

char		cast_int(t_types *var, char len[2])
{
  var->lls = (int)var->lls;
  if ((int)var->lls < 0)
    return (1);
  return (0);
}

char		cast_ssize_t(t_types *var, char len[2])
{
  if ((var->lls = (ssize_t)var->lls) < 0)
    return (1);
  return (0);
}

char		cast_ptrdiff_t(t_types *var, char len[2])
{
  if ((var->lls = (ptrdiff_t)var->lls) < 0)
    return (1);
  return (0);
}
