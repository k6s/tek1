/*
** inst_aff.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Apr  5 05:06:21 2015
** Last update Fri Apr 10 15:16:19 2015 
*/
#include <vm.h>

/*
** carry ?
*/

t_proc			*inst_aff(t_vm *vm, t_proc *s_proc, t_lst **vars)
{
  char			ocp;
  t_dir			*c_val;

  ocp = *(vm->arena + s_proc->pc++ % MEM_SIZE);
  if (!(s_proc->carry = check_args(&op_tab[E_AFF], s_proc, ocp)))
    return (next_inst(vm->arena, s_proc));
  if (!(c_val = reg_addr(vm, vars, s_proc)))
    return (NULL);
  my_putchar(es_dir_value(c_val) % 256);
  return (next_inst(vm->arena, s_proc));
}
