/*
** inst_ld.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Apr  3 03:08:37 2015
** Last update Fri Apr 10 15:12:43 2015 
*/
#include <vm.h>

t_proc		*inst_ld(t_vm *vm, t_proc *s_proc, t_lst **lst)
{
  t_dir		*src;
  t_reg		*dst;
  char		ocp;

  ocp = *(vm->arena + s_proc->pc++);
  s_proc->s_pc = s_proc->pc;
  if (!(s_proc->carry = check_args(&op_tab[E_LD], s_proc, ocp)))
    return (next_inst(vm->arena, s_proc));
  if (!(src = get_arg_addr(ARG_TYPE(ocp, 0), op_tab[E_LD].type[0],
			   s_proc, vm, lst)))
    return (NULL);
  if (!(dst = get_arg_addr(ARG_TYPE(ocp, 1), op_tab[E_LD].type[1],
			   s_proc, vm, lst)))
    return (NULL);
  *dst = *src;
  return (next_inst(vm->arena, s_proc));
}
