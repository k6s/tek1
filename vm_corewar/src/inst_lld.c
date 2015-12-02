/*
** inst_ld.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Apr  3 03:08:37 2015
** Last update Mon Apr  6 10:17:02 2015 Stéphane
*/
#include <vm.h>

t_proc		*inst_lld(t_vm *vm, t_proc *s_proc)
{
  t_dir		*src;
  t_reg		*dst;
  char		ocp;

  ocp = *(vm->arena + s_proc->pc++);
  s_proc->s_pc = s_proc->pc;
  if (!(s_proc->carry = check_args(&op_tab[E_LD], s_proc, ocp)))
    return (next_inst(vm->arena, s_proc));
  if (!(src = get_arg_addr_lld(ARG_TYPE(ocp, 0), op_tab[E_LD].type[0],
			   vm->arena, s_proc)))
    return (NULL);
  if (!(dst = get_arg_addr_lld(ARG_TYPE(ocp, 1), op_tab[E_LD].type[1],
			   vm->arena, s_proc)))
    return (NULL);
  *dst = *src;
  return (next_inst(vm->arena, s_proc));
}
