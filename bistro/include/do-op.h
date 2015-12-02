/*
** do-op.h for do-op in /home/cano_c/rendu/Piscine_C_J11/do-op
** 
** Made by
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Oct 20 11:16:36 2014
** Last update Sun Nov  9 04:53:32 2014 
*/

#ifndef DO_OP_H_
# define DO_OP_H_

# include <my.h>

typedef struct s_op	t_op;
typedef struct s_nb	t_nb;
typedef struct s_base	t_base;

struct			s_nb
{
  char			*nb;
  size_t		len;
  char			sign;
};

struct			s_op
{
  t_nb			*n1;
  t_nb			*n2;
  char			op;
  char			*base;
  int			base_len;
};

struct			s_base
{
  char			*base;
  int			base_len;
};

t_nb		*do_op(t_op *op, char *ops);

int		get_base_idx(char c, char *base);

int		clean_res(t_nb *res, int max_len, char *base, char sign);
char		order_operands(t_nb **n1, t_nb **n2);
char		get_sign(t_nb *n1, t_nb *n2, char min);
void		add_one(t_nb *res, int len, int base_len);
void		sub_one(t_nb *res, int len, int base_len);

t_nb		*inf_add(t_nb *n1, t_nb *n2, t_base *base, char *ops);
void		do_add(t_nb *res, t_nb *n1, t_nb *n2, t_base *base);
t_nb		*inf_sub(t_nb *n1, t_nb *n2, t_base *base, char *ops);
void		do_sub(t_nb *res, t_nb *n1, t_nb *n2, t_base *base);
t_nb		*inf_mul(t_nb *n1, t_nb *n2, t_base *base, char *ops);
t_nb		*inf_div(t_nb *n1, t_nb *n2, t_base *base, char *ops);
t_nb		*inf_mod(t_nb *n1, t_nb *n2, t_base *base, char *ops);

#endif /* !DO_OP_H_ */
