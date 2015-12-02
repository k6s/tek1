/*
** inst_live.c for corewar in /home/cano_c/rendu/ELEM/PSU_2014_vm_corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Mar 31 04:52:28 2015
** Last update Fri Apr 10 15:52:26 2015 
*/
#include <vm.h>

int			proc_alive(t_proc **s_proc, int *nb_procs,
				   ssize_t *max_live_cycles)
{
  t_proc		*p;
  int			nb_alive;

  p = *s_proc;
  nb_alive = 0;
  while (p)
    {
      if (p->alive)
	++nb_alive;
      p = p->next;
    }
  if (nb_alive == *nb_procs)
    *max_live_cycles -= CYCLE_DELTA;
  *nb_procs = nb_alive;
  return (nb_alive);
}

t_proc			*inst_live(t_vm *vm, t_proc *s_proc, t_lst **vars)
{
  t_dir			*player_num;
  t_player		*s_players;
  t_lst			*new;


  player_num = get_arg_addr(AG_DIR, T_DIR, s_proc, vm, vars);
  wattron(vm->wins[WIN_ARENA], COLOR_PAIR(3));
  if (!(new = dump_clvar(vm->wins[WIN_ARENA], vm->arena, vm->arena + s_proc->pc - 4,
			 sizeof(t_dir))))
    return (NULL);
  lst_append(vars, new);
  wattroff(vm->wins[WIN_ARENA], A_STANDOUT);
  s_players = vm->s_players;
  while (s_players && s_players->p_id != es_dir_value(player_num))
    s_players = s_players->next;
  if (s_players && s_players->alive)
    {
      s_players->alive = 1;
      s_proc->alive = 1;
      vm->winner = s_players;
    }
  if (++vm->nbr_live == NBR_LIVE && !(vm->nbr_live = 0))
    if (!(proc_alive(&vm->procs, &vm->nb_procs, &vm->max_live_cycles)))
      return (NULL);
  return (next_inst(vm->arena, s_proc));
}
