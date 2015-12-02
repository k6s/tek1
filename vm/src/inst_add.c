/*
** inst_add.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Mar 30 01:30:25 2015
** Last update Fri Apr 10 15:08:09 2015 
*/
#include <vm.h>

/*
** L'addition est faite sur des int32_t car sizeof(int32_t) == 4 == REG_SIZE
** independamment de l'OS / architecture utilise.
** Toute operation faite sur des registres doit donc etre realise sur des
** int32_t. (Pour les index ont utilisera des int16_t
** (sizeof(int16_t) == 2 == IND_SIZE))
*/

t_proc			*inst_add(t_vm *vm, t_proc *s_proc, t_lst **vars)
{
  char			ocp;
  t_reg      		*lhs;
  t_reg      		*rhs;
  t_reg			*dst;
  t_dir			res;

  my_putstr("add\n");
  ocp = *(vm->arena + ++s_proc->pc);
  if (ARG_TYPE(ocp, 0) != AG_REG || ARG_TYPE(ocp, 1) != AG_REG
      || ARG_TYPE(ocp, 2) != AG_REG)
    {
      s_proc->carry = 0;
      skip_arg(ARG_TYPE(ocp, 0), s_proc);
      skip_arg(ARG_TYPE(ocp, 1), s_proc);
      skip_arg(ARG_TYPE(ocp, 2), s_proc);
      return (next_inst(vm->arena, s_proc));
    }
  if (!(lhs = reg_addr(vm, vars, s_proc)))
    return (NULL);
  if (!(rhs = reg_addr(vm, vars, s_proc)))
    return (NULL);
  if (!(dst = reg_addr(vm, vars, s_proc)))
    return (NULL);
  res = es_dir_value(lhs) + es_dir_value(rhs);
  *dst = es_dir_value(&res);
  s_proc->carry = 1;
  return (next_inst(vm->arena, s_proc));
}

t_proc			*inst_sub(t_vm *vm, t_proc *s_proc, t_lst UN **vars)
{
  char			ocp;
  t_reg      		*lhs;
  t_reg      		*rhs;
  t_reg			*dst;
  t_dir			res;

  my_putstr("sub\n");
  ocp = *(vm->arena + ++s_proc->pc);
  if (ARG_TYPE(ocp, 0) != AG_REG || ARG_TYPE(ocp, 1) != AG_REG
      || ARG_TYPE(ocp, 2) != AG_REG)
    {
      s_proc->carry = 0;
      skip_arg(ARG_TYPE(ocp, 0), s_proc);
      skip_arg(ARG_TYPE(ocp, 1), s_proc);
      skip_arg(ARG_TYPE(ocp, 2), s_proc);
      return (next_inst(vm->arena, s_proc));
    }
  if (!(lhs = reg_addr(vm, vars, s_proc)))
    return (NULL);
  if (!(rhs = reg_addr(vm, vars, s_proc)))
    return (NULL);
  if (!(dst = reg_addr(vm, vars, s_proc)))
    return (NULL);
  res = es_dir_value(lhs) - es_dir_value(rhs);
  *dst = es_dir_value(&res);
  s_proc->carry = 1;
  return (next_inst(vm->arena, s_proc));
}
