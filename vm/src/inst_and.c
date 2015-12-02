/*
** inst_and.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Mar 31 19:02:06 2015
** Last update Fri Apr 10 15:11:47 2015 
*/
#include <vm.h>

int			check_args(op_t *op_desc, t_proc *s_proc, char ocp);

t_proc			*inst_and(t_vm *vm, t_proc *s_proc, t_lst **vars)
{
  char			ocp;
  t_reg			*dst;
  t_reg			*lhs;
  t_reg			*rhs;

  s_proc->s_pc = s_proc->pc;
  ocp = *(vm->arena + s_proc->pc++ % MEM_SIZE);
  if (!(s_proc->carry = check_args(&op_tab[E_AND], s_proc, ocp)))
    return (next_inst(vm->arena, s_proc));
  if (!(lhs = get_arg_addr(ARG_TYPE(ocp, 0), op_tab[E_AND].type[0],
			   s_proc, vm, vars)))
    return (NULL);
  if (!(rhs = get_arg_addr(ARG_TYPE(ocp, 1), op_tab[E_AND].type[1],
			   s_proc, vm, vars)))
    return (NULL);
  if (!(dst = reg_addr(vm, vars, s_proc)))
    return (NULL);
  *dst = *lhs & *rhs;
  return (next_inst(vm->arena, s_proc));
}

t_proc			*inst_or(t_vm *vm, t_proc *s_proc, t_lst **vars)
{
  char			ocp;
  t_reg			*dst;
  t_reg			*lhs;
  t_reg			*rhs;

  ocp = *(vm->arena + s_proc->pc++ % MEM_SIZE);
  if (!(s_proc->carry = check_args(&op_tab[E_OR], s_proc, ocp)))
    return (next_inst(vm->arena, s_proc));
  if (!(lhs = get_arg_addr_i(ARG_TYPE(ocp, 0), op_tab[E_OR].type[0],
			     s_proc, vm, vars)))
    return (NULL);
  if (!(rhs = get_arg_addr_i(ARG_TYPE(ocp, 1), op_tab[E_OR].type[1],
			     s_proc, vm, vars)))
    return (NULL);
  if (!(dst = reg_addr(vm, vars, s_proc)))
    return (NULL);
  *dst = *lhs | *rhs;
  return (next_inst(vm->arena, s_proc));
}

t_proc			*inst_xor(t_vm *vm, t_proc *s_proc, t_lst **vars)
{
  char			ocp;
  t_reg			*dst;
  t_reg			*lhs;
  t_reg			*rhs;

  ocp = *(vm->arena + s_proc->pc++ % MEM_SIZE);
  if (!(s_proc->carry = check_args(&op_tab[E_XOR], s_proc, ocp)))
    return (next_inst(vm->arena, s_proc));
  if (!(lhs = get_arg_addr_i(ARG_TYPE(ocp, 0), op_tab[E_XOR].type[0],
			     s_proc, vm, vars)))
    return (NULL);
  if (!(rhs = get_arg_addr_i(ARG_TYPE(ocp, 1), op_tab[E_XOR].type[1],
			     s_proc, vm, vars)))
    return (NULL);
  if (!(dst = reg_addr(vm, vars, s_proc)))
    return (NULL);
  *dst = *lhs ^ *rhs;
  return (next_inst(vm->arena, s_proc));
}
