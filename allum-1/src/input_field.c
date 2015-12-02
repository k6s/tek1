/*
** input_field.c for allum-1 in /home/cano_c/rendu/ELEM/CPE_2014_allum1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sat Feb 21 15:15:28 2015
** Last update Sun Feb 22 12:08:11 2015 Cano Chloe
*/
#include <allum-1.h>

void    		ask_user_input(const char *msg, t_point *pos, char sc)
{
  cur_goto(pos);
  write(1, msg, my_strlen(msg));
  if (sc)
    tputs(tgetstr("ve", NULL), 0, &tput_putc);
}
