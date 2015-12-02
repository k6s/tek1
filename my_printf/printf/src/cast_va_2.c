/*
** cast_va_2.c for printf in /home/k6/rendu/PSU_2014_my_printf
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Sun Nov 16 20:18:02 2014 Cano Chloe
** Last update Sun Nov 16 22:29:41 2014 
*/

#include <my.h>

char		cast_addr(t_types *var, char len[2])
{
  var->addr = (void *)(var->lls);
  return (0);
}

char		cast_intmax_t(t_types *var, char len[2])
{
  var->lls = (intmax_t)(var->lls);
  return (0);
}
