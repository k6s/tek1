/*
** eval_expr.h for eval_expr in /home/cano_c/rendu/Piscine_C_eval_expr
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Oct 24 09:10:08 2014
** Last update Sun Nov  9 17:01:21 2014 Cano Chloe
*/

#ifndef EVAL_EXPR_H_
# define EVAL_EXPR_H_

# include <do-op.h>

# define NUM		4
# define ADD		3
# define SUB		3
# define DIV		2
# define MUL		2
# define MOD		2
# define PARB		1
# define PARE		0
# define SIGN		-1
# define ERR		5
# define END		6

# define TYPE_INIT	0
# define TYPE_OP	1
# define TYPE_NB	2
# define TYPE_PAR_BEG	3
# define TYPE_PAR_END	4
# define TYPE_SIGN	5
# define TYPE_ERR	6
# define TYPE_END	7

# define SYNTAXE_ERROR_MSG	"Syntax Error\n"

typedef struct s_bistro	t_bistro;
typedef struct s_expr	t_expr;
typedef char (*t_pft)(t_bistro *, t_expr **, char *);

struct			s_expr
{
  char			type;
  int			elem;
  t_nb			*nb;
  t_expr		*next;
  t_expr		*prev;
};

struct			s_bistro
{
  int			str_len;
  char			*str;
  t_expr		*s_expr;
  char			*base;
  size_t		base_len;
  char			*ops;
  int			trail_spc;
  int			par;
};

t_nb	*evalexpr(char *str, char *base, char *ops, int len[2]);
int	is_valid(char *base, char *ops);
int	is_op(char c, char *ops);

char	p_end(t_bistro *bistro, t_expr **stack, char *ctt);
char	p_sign(t_bistro *bistro, t_expr **stack, char *ctt);
char	p_op(t_bistro *bistro, t_expr **stack, char *ctt);
char	p_nb(t_bistro *bistro, t_expr **stack, char *ctt);
char	p_parb(t_bistro *bistro, t_expr **stack, char *ctt);
char	p_pare(t_bistro *bistro, t_expr **stack, char *ctt);
char	p_e(t_bistro *bistro, t_expr **stack, char *ctt);

t_expr	*push(t_expr **stack, char op, t_nb *nb, char type);
t_expr	*pop(t_expr **stack);
void	stack_to_expr(t_expr **stack, t_expr *expr);
int	to_expr(t_expr **expr, t_nb *nb, char type);

t_pft	**parse_mtx(void);
char	*get_tok(char *base, char *ops);
char	*char_to_type(void);
void	free_tabs(t_pft **mtx, char *type);

int	get_base_idx(char c, char *base);
int	is_nb(char c, char *base);
char	zero_check(t_nb *s_nb, char zero, char min, char plus);
t_nb	*mk_zero(char zero);

#endif /* !EVAL_EXPR_H_ */
