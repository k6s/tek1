/*
** proc.c for corewar in /home/cano_c/rendu/ELEM/corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Mar 19 12:20:31 2015
** Last update Fri Apr 10 17:50:20 2015 
*/
#include <vm.h>

t_proc		*new_proc(t_player *s_player, off_t entry, off_t exit,
			  int id)
{
  t_proc	*new;

  if (!(new = my_memalloc(sizeof(*new))))
    return (NULL);
  my_memrevcpy(new->regs[0],  &s_player->p_id, DIR_SIZE);
  new->pc = entry;
  new->entry = entry;
  new->end = exit;
  new->id = id;
  return (new);
}

void		proc_append(t_proc **s_proc, t_proc *new, size_t turn)
{
  t_proc	*tmp;

  if (!*s_proc)
    {
      *s_proc = new;
      new->next = NULL;
      (*s_proc)->id = 0;
    }
  else
    {
      tmp = *s_proc;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
      new->turn = turn;
      new->next = NULL;
    }
}

int		update_pc(t_vm *vm, off_t pc, t_lst **vars, int color)
{
  t_lst		*new;

  wattron(vm->wins[WIN_ARENA], COLOR_PAIR(color));
  if (!(new = dump_clvar(vm->wins[WIN_ARENA], vm->arena,
			 vm->arena + pc - 1, 1)))
    return (-1);
  lst_append(vars, new);
  return (0);
}

t_proc		*step_proc(t_vm *vm, t_proc *s_proc, t_ft_inst *inst_ft,
			   t_lst **vars)
{
  int		opcode;
  t_proc	*next;

  next = NULL;
  if (s_proc->cycles > 0)
    {
      --s_proc->cycles;
      next = s_proc;
    }
  if (!(s_proc->cycles))
    {
      if ((opcode = *(char *)(vm->arena + s_proc->pc++)) <= MAX_OP
	  && opcode > 0 && opcode != 0x0C && opcode != 0x0D && opcode != 0x0E && opcode != 0x0F)
	{
	  update_pc(vm, s_proc->pc, vars, 4);
	  if (!(next = inst_ft[opcode - 1](vm, s_proc, vars)))
	    {
	      my_putstr("end program\n");
	    }
	}
      else
	{
	  next = s_proc;
	  if (s_proc->pc < s_proc->end)
	      s_proc->pc++;
	  else
	    next = NULL;
	}
    }
  return (next);
}

void		restore_vars_color(WINDOW *win, void *arena, t_lst *vars)
{
  t_lst		*tmp;

  while (vars)
    {
      restore_lvar(win, arena, vars->data, vars->len);
      tmp = vars;
      vars = vars->next;
      free(tmp);
    }
}

int		new_turn(t_vm *s_vm, t_proc **s_proc, t_ft_inst *inst_ft)
{
  t_proc	*tmp;
  t_proc	*new;
  t_proc	*next;
  t_lst		*vars;

  vars = NULL;
  while (*s_proc && (*s_proc)->turn == s_vm->turn)
    {
      new = step_proc(s_vm, *s_proc, inst_ft, &vars);
      tmp = *s_proc;
      next = (*s_proc)->next;
      if (new)
	proc_append(s_proc, new, s_vm->turn + 1);
      *s_proc = next;
      if (!new)
	free(tmp);
    }
  wrefresh(s_vm->wins[WIN_ARENA]);
  if (vars)
    {
      usleep(500000);
      restore_vars_color(s_vm->wins[WIN_ARENA], s_vm->arena, vars);
      wrefresh(s_vm->wins[WIN_ARENA]);
    }
  return (0);
}

t_ft_inst	*init_ft_inst(void)
{
  t_ft_inst	*inst_ft;

  if (!(inst_ft = my_memalloc(sizeof(*inst_ft) * 17)))
    return (NULL);
  inst_ft[E_LIVE] = &inst_live;
  inst_ft[E_LD] = &inst_ld;
  inst_ft[E_ST] = &inst_st;
  inst_ft[E_ADD] = &inst_add;
  inst_ft[E_SUB] = &inst_sub;
  inst_ft[E_AND] = &inst_and;
  inst_ft[E_OR] = &inst_or;
  inst_ft[E_XOR] = &inst_xor;
  inst_ft[E_ZJMP] = &inst_zjmp;
  inst_ft[E_STI] = &inst_sti;
  inst_ft[E_LDI] = &inst_sti;
  return (inst_ft);
}

int		procs_alive(t_proc **s_procs)
{
  t_proc	*p;
  t_proc	*prev;
  t_proc	*tmp;
  int		nb_alive;

  p = *s_procs;
  prev = NULL;
  nb_alive = 0;
  while (p)
    {
      tmp = NULL;
      if (p->alive)
	{
	  p->alive = 0;
	  ++nb_alive;
	}
      else
	{
	  tmp = p;
	  if (prev)
	    prev->next = p->next;
	  else
	    *s_procs = p->next;
	}
      p = p->next;
      free(tmp);
    }
  return (nb_alive);
}

int		players_alive(t_player *players, t_proc **s_procs)
{
  int		players_alive;
  int		nb_players;

  players_alive = 0;
  nb_players = 0;
  while (players)
    {
      if (players->alive > 0)
	{
	  /*       	  my_putstr("Player [");
	  my_put_nbr(players->p_id);
	  my_putstr("] :: \"");
	  my_putstr(players->name);
	  my_putstr("\" is alive.\n"); */
	  ++players_alive;
	  players->alive = -1;
	}
      ++nb_players;
      players = players->next;
    }
  if (!procs_alive(s_procs))
    return (0);
  return (players_alive);
}

void		put_hexchar(unsigned char c)
{
  my_putnbr_base(c / 16, "0123456789abcdef");
  my_putnbr_base(c % 16, "0123456789abcdef");
}

void		put_hexaddr(off_t addr, size_t len)
{
  const char	*base = "0123456789abcdef";

  if (--len > 0)
    put_hexaddr(addr / 16, len);
  my_putchar(base[addr % 16]);
}
/*
void		dump_line(char *arena, size_t idx)
{
  size_t	i;

  i = 0;
  put_hexaddr(idx, sizeof(idx));
  my_putstr(" | ");
  while (i < 16)
    {
      put_hexchar(*(arena + idx + i));
      my_putchar(' ');
      ++i;
    }
}
*/
/*void		dump_arena(char *arena)
{
  size_t	idx;

  idx = 0;
  my_putchar('\n');
  while ((MEM_SIZE - idx) / 16 > 0)
    {
      dump_line(arena, idx);
      my_putchar('\n');
      idx += 16;
    }
  while ((MEM_SIZE - idx) % 16 > 0)
    {
      put_hexchar(*(arena + idx));
      my_putchar(' ');
      ++idx;
    }
}*/

t_player	*start_game(t_vm *s_vm)
{
  t_ft_inst	*inst_ft;
  int		live_cycles;

  if (!(inst_ft = init_ft_inst()))
    return (NULL);
  s_vm->turn = 0;
  s_vm->max_live_cycles = CYCLE_TO_DIE;
  s_vm->nbr_live = 0;
  live_cycles = 0;
  while (s_vm->procs && s_vm->max_live_cycles > 0
	 && s_vm->max_cycles > (ssize_t)s_vm->turn)
    {
      new_turn(s_vm, &s_vm->procs, inst_ft);
      ++s_vm->turn;
      if ((ssize_t)s_vm->turn - live_cycles >= s_vm->max_live_cycles)
	{
	  if (!players_alive(s_vm->s_players, &s_vm->procs))
	    return (s_vm->winner);
	  live_cycles = s_vm->turn;
	}
    }
  endwin();
  /*
  if (s_vm->max_cycles < INT_MAX)
  dump_arena(s_vm->arena);*/
  return (s_vm->winner);
}
