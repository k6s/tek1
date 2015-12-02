/*
1;2802;0c** main.c for corewar in /home/cano_c/rendu/ELEM/corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Mar 18 14:09:38 2015
** Last update Fri Apr 10 17:51:34 2015 
*/
#include <vm.h>

void		dump_arena(char *arena, WINDOW *win)
{
  size_t	idx;

  idx = 0;
  while ((MEM_SIZE - idx) / 64 > 0)
    {
      dump_line((unsigned char *)arena, idx, win);
      waddch(win, '\n');
      idx += 64;
    }
  wrefresh(win);
}

void		*load_players(t_player *players, size_t nb_players,
			      t_proc **s_proc)
{
  char		*arena;
  size_t	idx;
  t_proc	*n_proc;

  idx = 0;
  if (!(arena = my_memalloc(sizeof(*arena) * MEM_SIZE)))
    return (NULL);
  while (idx < nb_players)
    {
      if (players->file_len - TEXT_OFF > MEM_SIZE / nb_players)
	return (NULL);
      if (!(n_proc = new_proc(players, (MEM_SIZE / nb_players) * idx,
			      (MEM_SIZE / nb_players) * idx + players->file_len
			      - TEXT_OFF, idx)))
	return (NULL);
      my_memcpy(n_proc->pc + arena, (char *)players->file + TEXT_OFF,
		players->file_len - TEXT_OFF);
      players = players->next;
      ++idx;
      proc_append(s_proc, n_proc, 0);
    }
  return (arena);
}

void		output_winner(t_player *winner)
{
  my_putstr("\nplayer [");
  my_put_nbr(winner->p_id);
  my_putstr("] :: \"");
  my_putstr(winner->name);
  my_putstr("\" wins.\n");
}

# define O_DUMP		1
# define O_PNUM		2
# define O_LDADDR	4

int		player_op(off_t *ld_addr, int32_t *p_id, char op, char ***arg)
{
  if (op == 'a' && *arg && **arg)
    {
      *ld_addr = atoi(**arg);
      return (O_LDADDR);
    }
  else if (op == 'n' && *arg && **arg)
    {
      *p_id = atoi(**arg);
      return (O_PNUM);
    }
  return (-1);
}

int		add_player(char **argv, char op, int *op_idx, char ***arg,
			   t_player **players)
{
  int		ops;
  int		n;
  int32_t	p_id;
  off_t		ld_addr;

  ld_addr = -1;
  p_id = -1;
  if ((ops = player_op(&ld_addr, &p_id, op, arg)) < 0)
    return (-1);
  if ((n = get_players(*arg + 1, players, &ld_addr, p_id != -1 ? &p_id : NULL)))
    return (n);
  while ((op = my_getopt(argv, "adn", op_idx, arg)) > 0)
    {
      if (op == 'a' || op == 'n')
	{
	  if ((n = player_op(&ld_addr, &p_id, op, arg)) < 0 || (n & ops))
	    return (-1);
	  ops |= n;
	}
      else
	return (-1);
      if ((n = get_players(*arg + 1, players, &ld_addr, &p_id)))
	return (n);
    }
  return (-1);
}

int		get_vm_opt(char **argv, t_player **players, int *max_cycles,
			   int *nb_players)
{
  char		o;
  int		ops;
  char		**arg;
  int		op_idx;

  ops = 0;
  op_idx = -1;
  while ((o = my_getopt(argv, "adn", &op_idx, &arg)) > 0)
    {
      if (o == 'd' && !(ops & O_DUMP))
	{
	  ops |= O_DUMP;
	  *max_cycles = atoi(*arg);
	  if (*(arg + 1) && (o = get_players(arg + 1, players, NULL, NULL)) < 0)
	    return (-1);
	  *nb_players += o;
	}
      else if (o != 'd')
	{
	  if ((o = add_player(argv, o, &op_idx, &arg, players)) < 1)
	    return (-1);
	  *nb_players += o;
	}
      else
	return (-1);
    }
  return (0);
}

int		get_cmdline(char **argv, t_player **players,
			    int *nb_players)
{
  int		max_cycles;
  int		op;

  *nb_players = 0;
  max_cycles = 0;
  if ((get_vm_opt(argv, players, &max_cycles, nb_players)) < 0)
    return (-1);
  if (!*nb_players)
    {
      if ((op = get_players(argv + 1, players, NULL, NULL)) < 1)
	return (-1);
      *nb_players += op;
    }
  return (!max_cycles ? INT_MAX : max_cycles);
}

void		usage(void)
{
  write(2, "usage: corewar [-dump nbr_cycle] [[-n prog_number]\
 [-a load_address] prog_name] ...\n", 84);
}

int		main(int UN argc, char **argv)
{
  t_vm		vm;
  t_player	*winner;

  vm.procs = NULL;
  vm.s_players = NULL;
  vm.winner = 0;
  if (!(vm.wins = curses_init()))
    return (-1);
  if ((vm.max_cycles = get_cmdline(argv, &vm.s_players, &vm.nb_procs)) < 0)
    {
      usage();
      return (-1);
    }
  if (vm.nb_procs < 2 || vm.nb_procs > 4)
    {
      usage();
      return (-1);
    }
  if (!(vm.arena = load_players(vm.s_players, vm.nb_procs, &vm.procs)))
    return (-1);
  printf("initialized a %dB arena with %d players\n", MEM_SIZE, vm.nb_procs);
  dump_arena(vm.arena, vm.wins[WIN_ARENA]);
  if ((winner = start_game(&vm)))
    output_winner(winner);
  free(vm.arena);
  if (!isendwin())
    endwin();
  return (0);
}
