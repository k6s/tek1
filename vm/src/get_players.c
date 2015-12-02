/*
** get_players.c for corewar in /home/cano_c/rendu/ELEM/corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Mar 18 17:21:42 2015
** Last update Wed Apr  8 18:16:29 2015 
*/
#include <vm.h>

static t_player	*new_player(char *filename)
{
  t_player	*player;
  size_t	file_len;
  int		fd;
  header_t	*h;

  if ((fd = open(filename, O_RDONLY)) < 0)
    return (NULL);
  if (!(player = my_memalloc(sizeof(*player))))
    return (NULL);
  if (!(player->file = get_file_content(fd, &file_len)))
    return (NULL);
  player->file_len = file_len;
  player->alive = -1;
  h = player->file;
  my_strncpy(player->name, h->prog_name, PROG_NAME_LENGTH + 1);
  close(fd);
  return (player);
}

void		append_player(t_player **players, t_player *new)
{
  t_player	*tmp;

  if (!*players)
    *players = new;
  else
    {
      tmp = *players;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
      new->next = NULL;
    }
}

ssize_t		get_players(char **argv, t_player **players, off_t *ld_addr,
			    int32_t *p_id)
{
  t_player	*new;
  size_t	nb_players;
  char		first;

  nb_players = 0;
  first = 1;
  if (p_id && (*p_id > 4 || *p_id < 1))
    return (-1);
  while (*argv && **argv != '-')
    {
      if (!(new = new_player(*argv)))
	return (-1);
      if (first)
	{
	  if (p_id)
	    new->p_id = *p_id;
	  if (ld_addr)
	    new->ld_addr = *ld_addr;
	  else
	    new->ld_addr = -1;
	  first = 0;
	}
      new->p_id = nb_players + 1;
      append_player(players, new);
      ++nb_players;
      ++argv;
    }
  return (nb_players);
}
