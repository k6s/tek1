/*
** main.c for allum1 in /home/cano_c/rendu/ELEM/CPE_2014_allum1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 16 11:10:13 2015
** Last update Sun Feb 22 12:06:25 2015 Cano Chloe
*/
#include <allum-1.h>

void			print_allum(int nb_row, t_point *margin)
{
  t_point      		start;
  size_t		row_len;
  size_t		n;

  tputs(tgetstr("ho", NULL), 0, &tput_putc);
  start.x = margin->x + nb_row - 1;
  start.y = margin->y;
  row_len = 1;
  while (start.y < 4 + nb_row)
    {
      cur_goto(&start);
      n = 0;
      while (n++ < row_len)
	write(1, "|", 1);
      ++start.y;
      --start.x;
      row_len += 2;
    }
}

void			print_header(int margin)
{
  const char		*header = "---= [ ALLUM I ] =---";
  size_t		hlen;
  t_point		pos;

  hlen = my_strlen(header);
  pos.x = margin - 6;
  pos.y = 0;
  tputs(tgetstr("cl", NULL), 0, &tput_putc);
  cur_goto(&pos);
  write(1, header, my_strlen(header));
}

int			main(int argc, char **argv, char **environ)
{
  int			nb_row;
  t_point      		margin;
  struct termios	*term_save;
  int			mode;

  nb_row = 4;
  margin.x = 10;
  margin.y = 4;
  if ((term_save = term_raw(environ)))
    {
      print_header(margin.x);
      mode = choose_mode(&margin);
      print_allum(nb_row, &margin);
      start_game(nb_row, &margin, mode);
      sleep(2);
      tputs(tgetstr("cl", NULL), 0, &tput_putc);
      tputs(tgetstr("ve", NULL), 0, &tput_putc);
      tcsetattr(0, TCSANOW, term_save);
      free(term_save);
    }
  else
    return (-1);
  return (0);
}
