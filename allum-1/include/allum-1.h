/*
** allum-1.h for allum-1 in /home/k6/epitech/ELEM/allum-1
** 
** Made by Chloe Cano
** Login   <k6@epitech.net>
** 
** Started on  Fri Feb 13 21:35:06 2015
** Last update Sun Feb 22 11:27:50 2015 
*/
#ifndef ALLUM_1_H_
# define ALLUM_1_H_

#include <term.h>

# define PLAYER1	0
# define PLAYER2	1

# define MODE_PVP	1
# define MODE_PVC	2

# define MUL_LINE	0
# define SOL_LINE	1
# define MUL_LINE_LEN	2

int		choose_mode(t_point *margin);
int		select_row(int *map, int *pos_r, int nb_row, t_point *margin);
int		remove_allum(int *pos_r, int nb_row, int *map, t_point *margin);
int		end_game(int *map, int nb_row);
void		ask_user_input(const char *msg, t_point *pos, char sc);

#endif /* !ALLUM_1_H_ */
