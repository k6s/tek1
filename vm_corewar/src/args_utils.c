/*
** args_utils.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Mar 31 01:05:00 2015 
** Last update Fri Apr 10 18:22:04 2015 Stéphane
*/

#include <vm.h>

int			update_arg(t_vm *vm, t_lst **vars, int *desc, void *arg)
{
  t_lst			*new;

  wattron(vm->wins[WIN_ARENA], COLOR_PAIR(desc[0]));
  if (!(new = dump_clvar(vm->wins[WIN_ARENA], vm->arena, arg, desc[1])))
    return (-1);
  lst_append(vars, new);
  wrefresh(vm->wins[WIN_ARENA]);
  return (0);
}

void			skip_arg(args_type_t arg_type, t_proc *s_proc)
{
  if (arg_type == AG_REG)
    ++s_proc->pc;
  else if (arg_type == AG_DIR)
    s_proc->pc += DIR_SIZE;
  else if (arg_type == AG_IND)
    s_proc->pc += IND_SIZE;
}

int			check_args(op_t *op_desc, t_proc *s_proc, char ocp)
{
  int			idx;
  const args_type_t	a_type[3] = {T_REG, T_DIR, T_IND};

  idx = 0;
  while (idx < op_desc->nbr_args)
    {
      if (!ARG_TYPE(ocp, idx)
	  || !(a_type[ARG_TYPE(ocp, idx) - 1] & op_desc->type[idx]))
	idx = op_desc->nbr_args;
      ++idx;
    }
  if (idx != op_desc->nbr_args)
    {
      idx = 0;
      while (idx++ < op_desc->nbr_args)
	skip_arg(ARG_TYPE(ocp, idx - 1), s_proc);
      return (0);
    }
  return (1);
}
