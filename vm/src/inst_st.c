/*
** inst_st.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Apr  3 03:09:04 2015 
** Last update Fri Apr 10 15:15:50 2015 
*/
#include <vm.h>

/*
** carry ?
*/

t_proc			*inst_st(t_vm *vm, t_proc *s_proc, t_lst UN **vars)
{
  char			ocp;
  t_dir			*src;
  t_dir			*dst;

  s_proc->s_pc = s_proc->pc;
  ocp = *(vm->arena + s_proc->pc++);
  if (!(s_proc->carry = check_args(&op_tab[E_ST], s_proc, ocp)))
    return (next_inst(vm->arena, s_proc));
  if (!(src = get_arg_addr(ARG_TYPE(ocp, 0), op_tab[E_ST].type[0],
			   s_proc, vm, vars)))
    return (NULL);
  if (!(dst = get_arg_addr(ARG_TYPE(ocp, 1), op_tab[E_ST].type[1],
			   s_proc, vm, vars)))
    return (NULL);
  *dst = *src;
  s_proc->carry = 0;
  return (next_inst(vm->arena, s_proc));
}
