/*
** inst_utils.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Mar 30 01:15:26 2015 
** Last update Fri Apr 10 16:59:03 2015 
*/
#include <vm.h>

t_proc			*next_inst(char *arena, t_proc *s_proc)
{
  int			opcode;

  if ((opcode = *(arena + s_proc->pc % MEM_SIZE)) < 16 && opcode > 0)
    {
      s_proc->turn++;
      s_proc->cycles = op_tab[opcode - 1].nbr_cycles;
      return (s_proc);
    }
  my_putstr("Wrong opcode ");
  my_put_nbr(*(arena + s_proc->pc - 1));
  my_putchar('\n');
  return (NULL);
}
