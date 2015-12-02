/*
** libmy.h for libmy.h in /home/k6/rendu/Piscine_C_J08
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Wed Oct  8 15:50:16 2014
** Last update Mon Dec  1 19:53:41 2014 
*/

#ifndef LIBMY_H_
# define LIBMY_H_

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define ABS(val)	((val) >= 0 ? (val) : (val) * -1)

# define UN		__attribute__((unused))

void		my_putchar(char c);
int		my_isneg(int nb);
int		my_put_nbr(int nb);
int		my_putnbr_base(int nb, char *base);
int		my_swap(int *a, int *b);
int		my_putstr(char *str);
int		my_putstr_fd(char *str, int fd);
int		my_strlen(char *str);

int		my_getnbr(char *str);
size_t		get_nbr_len(int n);
int		my_getnbr_base(char *str, char *base, size_t base_len);
void		my_sort_int_tab(int *tab, int size);
int		my_power_rec(int nb, int power);
int		my_square_root(int nb);
int		my_isprime(int nombre);
int		my_find_prime_sup(int nb);
char		*convert_base(char *nbr, char *base_from, char *base_to);
int		get_base_len(char *base);

char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int nb);
int		my_strccmp(char *s1, char *s2);
int		my_stracmp(char *s1, char *s2);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		is_nbr(char *str);
int		my_showstr(char *str);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int nb);
int		my_strlcat(char *dest, char *src, int size);
char		*my_strdup(char *src);

char		**my_str_to_wordtab(char *str);
int		my_show_wordtab(char **tab);

int		my_showmem(char *str, int size);
void		my_bzero(void *mem, int len);
void		my_memcpy(void *dst, const void *src, size_t len);
int		my_memcmp(void *s1, void *s2, int len);
void		*my_memmove(void *dest, void *src, size_t len);

/*
** Sort argv argument first, then options. If an option in argv is not
** acknowledged in op string, returns -2, else return the option character.
** It also set op_idx to the index of the option which has just been processed.
** When no more option is to be found in argv, op_idx contains the index
** of the first option in argv or -1 if there is none, and my_getopt returns -1.
*/

int		my_getopt(char **argv, char *ops, int *op_idx);

typedef struct s_blk	t_blk;
typedef struct s_stree	t_stree;
typedef struct s_lst	t_lst;

struct		s_blk
{
  void		*data;
  size_t       	len;
};

t_blk		*blk_new(size_t data_len);

struct		s_lst
{
  t_blk		blk;
  t_lst		*next;
  t_lst		*prev;
};

/*
** Return the newly created t_lst elem, or NULL if malloc failed.
** If blk is null, set data and len to 0 instead of blk->data and blk->len.
*/
t_lst		*lst_new(t_blk *blk);
t_lst		*lst_new_data(void *data, size_t data_len);
int		lst_insert(t_lst **lst, t_blk *blk, int (*cmp)());

/*
** FIFO
*/

t_lst		*lst_pop(t_lst **stack);
void		lst_push(t_lst **stack, t_lst *elem);
/*
** Free all the elems and elems data in stack, the set *stack to NULL.
*/
void		lst_sclear(t_lst **stack);
/*
** swap the first and second elem of the stack if there is at least
** 2 elems. Return 1 if swap as been done, 0 if not.
*/
char		lst_swap(t_lst **stack);
/*
** Move the first elem to the end of the stack. Returns 1 if rot has been done,
** else returns 0 (is there is less than 2 elems in stack).
*/
char		lst_rot(t_lst **stack);
/*
** same as lst_rot, except that it moves the last elem to the beggining of the
** stack.
*/
char		lst_rrot(t_lst **stack);

#endif /* !LIBMY_H_ */
