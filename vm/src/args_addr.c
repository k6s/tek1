/*
** args_addr.c for  in /home/alpha/rendu/vm/src
**
** Made by Stéphane
** Login   <alpha@epitech.net>
**
** Started on  Fri Apr 10 18:17:07 2015 Stéphane
** Last update Fri Apr 10 18:21:14 2015 Stéphane
*/

#include <vm.h>

void			*dir_addr(t_vm *vm, t_lst **vars, t_proc *s_proc)
{
  void			*var;
  int			desc[2];

  desc[0] = 2;
  desc[1] = DIR_SIZE;
  var = vm->arena + s_proc->pc % MEM_SIZE;
  update_arg(vm, vars, desc, var);
  s_proc->pc += DIR_SIZE;
  return (var);
}

void			*reg_addr(t_vm *vm, t_lst **vars, t_proc *s_proc)
{
  size_t		reg_num;
  int			desc[2];
  t_reg			*reg;

  desc[0] = 2;
  desc[1] = 1;
  if (!(reg_num = *(vm->arena + s_proc->pc++ % MEM_SIZE))
      || reg_num > REG_NUMBER)
    return (NULL);
  reg = (t_reg *)s_proc->regs[reg_num - 1];
  update_arg(vm, vars, desc, vm->arena + (s_proc->pc - 1) % MEM_SIZE);
  return (reg);
}

void			*get_arg_addr_i(args_type_t arg_type, args_type_t types,
					t_proc *s_proc, t_vm *vm, t_lst **vars)
{
  if (arg_type == AG_REG && (types & T_REG))
    return (reg_addr(vm, vars, s_proc));
  if (arg_type == AG_DIR && (types & T_DIR))
    return (dir_addr(vm, vars, s_proc));
  if (arg_type == AG_IND && (types & T_IND))
    return (ind_addr_i(vm, vars, s_proc));
  return (NULL);
}

void			*ind_addr(t_vm *vm, t_lst **vars, t_proc *s_proc)
{
  t_ind			*ind;
  t_dir			*dir;
  int			desc[2];

  desc[0] = 2;
  desc[1] = IND_SIZE;
  ind = (t_ind *)(vm->arena + s_proc->pc % MEM_SIZE);
  update_arg(vm, vars, desc, ind);
  s_proc->pc += IND_SIZE;
  dir = (t_dir *)((s_proc->s_pc + es_ind_value(ind) % IDX_MOD) % MEM_SIZE
		  + vm->arena);
  update_arg(vm, vars, desc, dir);
  return (dir);
}

void			*get_arg_addr(args_type_t type, args_type_t types,
				      t_proc *s_proc, t_vm *vm, t_lst **vars)
{
  if (type == AG_REG && (types & T_REG))
    return (reg_addr(vm, vars, s_proc));
  if (type == AG_DIR && (types & T_DIR))
    return (dir_addr(vm, vars, s_proc));
  if (type == AG_IND && (types & T_IND))
    return (ind_addr(vm, vars, s_proc));
  return (NULL);
}
