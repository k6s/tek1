/*
** inst_lldi.c for  in /home/alpha/rendu/vm/src
**
** Made by Stéphane
** Login   <alpha@epitech.net>
**
** Started on  Mon Apr  6 10:35:09 2015 Stéphane
** Last update Mon Apr  6 10:47:57 2015 Stéphane
*/

#include <vm.h>

t_proc			*inst_lldi(t_vm *vm, t_proc *s_proc)
{
  char			ocp;
  t_ind			*lhs;
  t_ind			*rhs;
  t_dir			*dst;
  t_dir			*src;

  s_proc->s_pc = s_proc->pc;
  ocp = *(arena + s_proc->pc++ % MEM_SIZE);
  if (!(s_proc->carry = check_args(op_tab[E_LDI], s_proc, ocp)))
    return (next_inst(vm->arena, s_proc));
  if (!(lhs = get_arg_addr_i(ARG_TYPE(ocp, 0, op_tab[E_LDI].type[0],
				      vm->arena, s_proc))))
    return (NULL);
  s_proc->pc = s_proc->s_pc + IND_SIZE + 1;
  if (!(rhs = get_arg_addr_i(ARG_TYPE(ocp, 0, op_tab[E_LDI].type[0],
				      vm->arena, s_proc))))
    return (NULL);
  s_proc->pc = s_proc->s_pc + 2 * IND_SIZE + 1;
  if (!(dst = reg_addr(vm->arena, s_proc)))
    return (NULL);
  src = (t_dir *)((es_ind_value(lhs) + es_ind_value(rhs))
		  + s_proc->entry + vm->arena);
  *dst = *src;
  return (next_inst(vm->arena, s_proc));
}
