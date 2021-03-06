/*
** args_utils_2.c for  in /home/alpha/rendu/vm/src
**
** Made by Stéphane
** Login   <alpha@epitech.net>
**
** Started on  Fri Apr 10 18:10:46 2015 Stéphane
** Last update Fri Apr 10 18:22:29 2015 Stéphane
*/

#include <vm.h>

void		*get_arg_addr_lld(args_type_t type, args_type_t types,
					  char *arena, t_proc *s_proc)
{
  if (type == AG_REG && (types & T_REG))
    return (reg_addr(arena, s_proc));
  if (type == AG_DIR && (types & T_DIR))
    return (dir_addr(arena, s_proc));
  if (type == AG_IND && (types & T_IND))
    return (ind_addr_lld(arena, s_proc));
  return (NULL);
}

void			*ind_addr_lld(char *arena, t_proc *s_proc)
{
  t_ind			*ind;
  t_dir			*dir;

  ind = (t_ind *)(arena + s_proc->pc % MEM_SIZE);
  s_proc->pc += IND_SIZE;
  dir = (t_dir *)((s_proc->s_pc + es_ind_value(ind)) % MEM_SIZE
		  + arena);
  return (dir);
}
