/*
** inst_sti.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Mar 31 00:13:47 2015
** Last update Fri Apr 10 17:48:02 2015 
*/
#include <vm.h>

t_proc			*inst_sti(t_vm *vm, t_proc *s_proc, t_lst **vars)
{
  char			ocp;
  t_ind			*lhs;
  t_ind			*rhs;
  t_reg			*src;
  t_dir			*dst;
  t_lst			*new;

  ocp = *(vm->arena + s_proc->pc++);
  s_proc->s_pc = s_proc->pc;
  if (!(src = get_arg_addr_i(ARG_TYPE(ocp, 0), op_tab[E_STI].type[0],
			     s_proc, vm, vars)))
    return (NULL);
  if (!(lhs = get_arg_addr_i(ARG_TYPE(ocp, 1), op_tab[E_STI].type[1],
			     s_proc, vm, vars)))
    return (NULL);
  if (ARG_TYPE(ocp, 0) != T_IND)
    s_proc->pc -= DIR_SIZE - IND_SIZE;
  if (!(rhs = get_arg_addr_i(ARG_TYPE(ocp, 2), op_tab[E_STI].type[2],
			     s_proc, vm, vars)))
    return (NULL);
  if (ARG_TYPE(ocp, 0) != T_IND)
    s_proc->pc -= DIR_SIZE - IND_SIZE;
  dst = (t_dir *)(es_ind_value(lhs) + es_ind_value(rhs) + s_proc->entry
		  + vm->arena);
  *dst = *src;
  wattron(vm->wins[WIN_ARENA], COLOR_PAIR(2));
  if (!(new = dump_clvar(vm->wins[WIN_ARENA], vm->arena, (char *)dst,
			 DIR_SIZE)))
    return (NULL);
  lst_append(vars, new);
  wattroff(vm->wins[WIN_ARENA], A_STANDOUT);
  return (next_inst(vm->arena, s_proc));
}
