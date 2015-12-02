/*
** start_game.c for allum-1.h in /home/k6/epitech/ELEM/allum-1
** 
** Made by Chloe Cano
** Login   <k6@epitech.net>
** 
** Started on  Fri Feb 13 22:55:16 2015
** Last update Sun Feb 22 12:02:35 2015 Cano Chloe
*/
#include <allum-1.h>

int			end_game(int *map, int nb_row)
{
  while (--nb_row > -1)
    {
      if (map[nb_row])
	return (0);
    }
  return (1);
}

static int		run_loop(int *map, int nb_row, t_point *margin)
{
  int			key;
  int			pos_r;
  int			end;
  int			player;
  const char		players_name[][NAME_MAX] = {"you", "computer"};

  pos_r = 1;
  end = 0;
  while (!end)
    {
      player = PLAYER2;
      if (!(select_row(map, &pos_r, nb_row, margin)))
	return (0);
      if (!(end = remove_allum(&pos_r, nb_row, map, margin)))
	{
	  sleep(1);
	  player = PLAYER1;
	  end = ia_move(&pos_r, nb_row, map, margin);
	}
      if (end < 0)
	return (0);
    }
  my_putstr((char *)players_name[player]);
  my_putstr(" win !\n");
  return (end);
}

void			name_player(char *player)
{
  t_point		pos;
  int			idx;

  pos.x = 2;
  pos.y = 2;
  cur_goto(&pos);
  idx = 0;
  while (++idx < NAME_MAX)
    write(1, " ", 1);
  cur_goto(&pos);
  write(1, player, my_strlen(player));
  free(player);
}

static int		run_loop_pvp(int *map, int nb_row, t_point *margin)
{
  int			key;
  int			pos_r;
  int			end;
  int			player;
  const char		players_name[][NAME_MAX] = {"player1", "player2"};

  pos_r = 1;
  end = 0;
  while (!end && (player = PLAYER2))
    {
      if (!(select_row(map, &pos_r, nb_row, margin)))
	return (0);
      if (!(end = remove_allum(&pos_r, nb_row, map, margin)))
	{
	  sleep(1);
	  if (!(player = PLAYER1) && !(select_row(map, &pos_r, nb_row, margin)))
	    return (0);
	  end = remove_allum(&pos_r, nb_row, map, margin);
	}
      if (end < 0)
	return (0);
    }
  my_putstr((char *)players_name[player]);
  my_putstr(" win !\n");
  return (end);
}

int			start_game(int nb_row, t_point *margin, int mode)
{
  int			*map;
  int			pos_r;
  int			len_r;
  t_point		pos;

  if (!(map = malloc(sizeof(*map) * nb_row)))
    return (-1);
  pos_r = 0;
  len_r = 1;
  while (pos_r < nb_row)
    {
      map[pos_r] = len_r;
      len_r += 2;
      ++pos_r;
    }
  select_line(1, margin, &pos_r);
  if (mode == MODE_PVP)
    run_loop(map, nb_row, margin);
  else
    run_loop_pvp(map, nb_row, margin);
  free(map);
  return (1);
}
