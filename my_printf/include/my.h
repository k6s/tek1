/*
** libmy.h for libmy.h in /home/k6/rendu/Piscine_C_J08
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Wed Oct  8 15:50:16 2014 Cano Chloe
** Last update Sun Nov 16 21:48:44 2014 
*/

#ifndef LIBMY_H_
# define LIBMY_H_

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <inttypes.h>

int		my_putchar(char c);
int		my_isneg(int nb);
int		my_put_nbr(int nb);
int		my_putnbr_base(int nb, char *base);
int		my_swap(int *a, int *b);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		my_getnbr_base(char *str, char *base);
void		my_sort_int_tab(int *tab, int size);
int		my_power_rec(int nb, int power);
int		my_square_root(int nb);
int		my_isprime(int nombre);
int		my_find_prime_sup(int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int nb);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_showstr(char *str);
int		my_showmem(char *str, int size);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int nb);
int		my_strlcat(char *dest, char *src, int size);
char		*my_strdup(char *src);
char		*convert_base(char *nbr, char *base_from, char *base_to);
int		get_base_len(char *base);
char		**my_str_to_wordtab(char *str);
int		my_show_wordtab(char **tab);
char		*my_strdup(char *str);
void		my_bzero(char *mem, unsigned int len);

/*
** PRINTF
** =============================================================================
*/

typedef struct s_printf		t_printf;
typedef struct s_printf_s	t_printf_s;
typedef union u_types		t_types;
typedef int			(*t_print_ft)(t_printf *);

# define F_MIN	1
# define F_PLS	2
# define F_SPC	4
# define F_DIZ	8

struct		s_printf
{
  va_list	ap;
  int		(*ft_get_va[256])(t_printf *, t_printf_s *);
  char		(*ft_cast[256])(t_types *var, char len[2]);
};

union			u_types
{
  signed long long	lls;
  unsigned long long	llu;
  long double		ldouble;
  char			*str;
  void			*addr;
  char			c;
};

struct			s_printf_s
{
  char			*str;
  t_types		var;
  ssize_t		width;
  ssize_t		prec;
  char			neg;
  char			nb;
  char			len[2];
  char			conv;
  char			fill;
  char			before;
};

int		my_printf(char *str, ...);

/*
** format_output.c
*/
int		spc_padding(size_t plen, ssize_t width, char fill);

/*
** parse_flags.c
*/
void		get_width(t_printf_s *s_str);
char		get_len(t_printf_s *s_str);
char		get_flags(t_printf *s_printf, t_printf_s *s_str);

/*
** parse_str.c
*/
int		parse_str(t_printf *s_printf, t_printf_s *s_str);

/*
** print_va.c
*/
int		output_va(t_printf *s_printf, t_printf_s *s_str);
int		output_integer(t_printf_s *s_str, int base_len);
int		output_char(t_printf_s *s_str);
int		output_str(t_printf_s *s_str);

/*
** get_va.c
*/
int		get_ll(t_printf *s_printf, t_printf_s *s_str);
int		get_ldouble(t_printf *s_printf, t_printf_s *s_str);
int		get_str(t_printf *s_printf, t_printf_s *s_str);
int		get_char(t_printf *s_printf, t_printf_s *s_str);
int		get_char(t_printf *s_printf, t_printf_s *s_str);

/*
** cast_va.c
*/
char		cast_char_short(t_types *var, char len[2]);
char		cast_long_llong(t_types *var, char len[2]);
char		cast_int(t_types *var, char len[2]);
char		cast_ssize_t(t_types *var, char len[2]);
char		cast_ptrdiff_t(t_types *var, char len[2]);
char		cast_addr(t_types *var, char len[2]);
char		cast_intmax_t(t_types *var, char len[2]);

/*
** print_*.c
*/
int		put_ll_reg(t_types *var, char conv, int base_len);
int		put_ll_base(t_types *var, char *base, unsigned int base_len);

int		get_ll_len(t_types *var, char conv, unsigned int base_len);

#endif /* !LIBMY_H_ */
