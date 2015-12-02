/*
** inst_zjmp.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Mar 31 04:44:21 2015
** Last update Fri Apr 10 15:55:46 2015 
*/
#include <vm.h>

t_ind			get_ind_content(char *big);

t_proc			*inst_zjmp(t_vm *s_vm, t_proc *s_proc, t_lst **vars)
{
  t_ind			*addr;
  char			*p;
  char			off[4];
  t_ind			test;
  t_lst		        *new;

  my_bzero(off, 4);
  addr = (t_ind *)(s_vm->arena + s_proc->pc);
  wattron(s_vm->wins[WIN_ARENA], COLOR_PAIR(2));
  if (!(new = dump_clvar(s_vm->wins[WIN_ARENA], s_vm->arena,
			 (char *)addr, IND_SIZE)))
    return (NULL);
  lst_append(vars, new);
  s_proc->pc += IND_SIZE;
  test = *(t_ind *)addr;
  p = (char *)&test;
  off[1] = (char)*(p);
  off[0] = (char)*(p + 1);
  if (s_proc->carry)
    s_proc->pc -= *(t_ind *)off * -1 % IDX_MOD + IND_SIZE + 1;
  return (next_inst(s_vm->arena, s_proc));
}
