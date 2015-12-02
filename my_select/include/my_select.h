/*
** my_select.h for my_select in /home/k6/epitech/MATHS/104intersection/my_select
** 
** Made by Chloe Cano
** Login   <k6@epitech.net>
** 
** Started on  Mon Jan  5 00:07:02 2015
** Last update Sun Jan 11 19:37:52 2015 
*/
#ifndef MY_SELECT_H_
# define MY_SELECT_H_

# include <my.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>

# define K_NB		5
# define K_UP		4283163
# define K_DO		4348699
# define K_SELCT	32
# define K_ESC		27
# define K_DONE		10

typedef struct		s_select
{
  char			*entry;
  size_t		len;
  char			selected;
  struct s_select	*next;
  struct s_select	*prev;
} t_select;

typedef struct		s_menu_term
{
  struct termios	*term_save;
  t_select		*entries;
  t_select		*entry;
  struct winsize	ws;
  t_point		size;
  t_point		orig;
  t_point		pos;
  size_t		col_size;
  size_t		nb_entries;
} t_menu_term;

t_select		*new_selem(char *entry);
void			selem_pushback(t_select *entry, t_select **orig,
				       size_t *co_size);
int			selem_print(t_menu_term *menu_term);
void			screen_to_small(t_menu_term *menu_term);

int			tput_putc(int c);
void			c_vmove(char *cp, int n);

/*
** FILE -> select_termcap.c
*/
struct termios		*tc_init(struct termios *term, char **environ);
void			tc_reset(struct termios *term);

/*
** FILE -> menu_entry.c
*/

/*
** draw a menu entry on screen
*/
void			put_str_caps(t_select **c_entry, int col_size);
/*
** erase a menu entry on screen
*/
void			erase_menu_entry(int col_size);

/*
** FILE -> cur_goto.c
*/

/*
** Place cursor at relative coordinates pos from orig
*/
void			cur_goto(t_point *pos, t_point *orig);
/*
** place cursor and set menu_term->entry to the first entry in the menu
*/
void			cur_goto_menu(t_menu_term *menu_term);
/*
** place cursor and set menu_term->entry to the next entry in the menu
*/
void			cur_goto_next(t_menu_term *menu_term);
/*
** place cursor and set menu_term->entry to the previous entry in the menu
*/
void			cur_goto_prev(t_menu_term *menu_term);
/*
** place cursor back len character
*/
void			cur_goto_cprev(size_t len);

/*
** FILE -> key_event.c
*/
typedef void		(*t_event_fp)(t_menu_term *, int);

int			call_event(char *read_buff, t_menu_term *menu_term, int argc);

/*
** FILE -> ev_done.c
*/
void			ev_done(t_menu_term *term, int argc);

#endif /* !MY_SELECT_H_ */
