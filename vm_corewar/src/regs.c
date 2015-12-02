/*
** regs.c for corewar in /home/cano_c/rendu/ELEM/corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Mar 19 13:29:22 2015
** Last update Thu Mar 19 15:22:27 2015 
*/
#include <vm.h>

/*
long long	get_nbr_len(char *addr, size_t len)
{
  long long	result;
  char		*r_ptr;

  result = 0;
  r_ptr = (char *)(&result);
  while (len-- > 0)
      r_ptr[len] = addr[len];
  return (result);
}

void		*ind_arg(t_proc *p, void *arena, t_blk *arg)
{
  void		*arg_addr;
  long long	arg_value;

  arg_off = get_nbr_len(p->pc + arena, IND_SIZE);
  arg->data = (void *)((p->pc + (arg_off % IDX_MOD)) % MEM_SIZE) + arena;
  arg->type = ARG_IND;
}

void		*reg_arg(t_proc *p, off_t reg, t_blk *arg)
{
  arg->data = p->regs[reg % REG_NUMBER];
  arg->type = ARG_REG;
}

void		*dir_arg(t_proc *proc, off_t UN off)
{
  return (p->pc);
}

void		*param_addr(t_proc *proc, void *arena, t_ft_param get_param)
{
  char		type;
  t_blk		*param;

  type = *(char *)(arena + proc->pc);
}
*/
