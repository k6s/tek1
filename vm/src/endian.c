/*
** endian.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Apr  3 03:24:18 2015
** Last update Fri Apr  3 03:24:26 2015 
*/
#include <vm.h>

t_ind			es_ind_value(const t_ind *src)
{
  t_ind			rev;

  rev = 0;
  my_memrevcpy(&rev, (const char *)src, IND_SIZE);
  return (rev);
}

t_dir			es_dir_value(const t_dir *src)
{
  t_dir			rev;

  rev = 0;
  my_memrevcpy(&rev, src, DIR_SIZE);
  return (rev);
}
