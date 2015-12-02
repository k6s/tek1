/*
** libterm.h for libterm in /home/k6/epitech/ELEM/allum-1
** 
** Made by Chloe Cano
** Login   <k6@epitech.net>
** 
** Started on  Fri Feb 13 21:54:21 2015
** Last update Fri Feb 13 22:47:36 2015 
*/
#ifndef TERM_H_
# define TERM_H_

# include <my.h>
# include <termios.h>
# include <termcap.h>

# define K_UP           4283163
# define K_DO           4348699
# define K_SELCT        32
# define K_ESC          27
# define K_DONE         10

/*
** set terminal to raw mode and return a backup of the old
** settings
*/
struct termios		*term_raw(char **environ);

/*
** tgetstr put function pointer argument
*/
int			tput_putc(int c);

/*
** move cursor to given coordinates both in memory and on screen
*/
void			cur_goto(t_point *pos);

/*
** Visually select a line.
*/
void			select_line(int line, t_point *margin, int *pos_r);

long long		term_getunbr(long long max);

#endif /* !TERM_H_ */
