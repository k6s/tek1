/*
** misc.c for Bistro in /home/cano_c/rendu/ELEM/Bistromatique
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Thu Oct 30 00:27:49 2014
** Last update Sun Nov  9 17:27:28 2014 Cano Chloe
*/

#include <eval_expr.h>

int		is_nb(char c, char *base)
{
  int		idx;

  idx = 0;
  while (base[idx])
    {
      if (base[idx] == c)
	return (idx);
      ++idx;
    }
  return (-1);
}

/*
** C_PARE  C_PARB  C_OP1  C_OP2  C_BASE ERR END  |
** ==========================================================
** ERR     PARB    ERR    SIGN   NB     ERR END  | TYPE_INIT
** ERR     PARB    ERR    SIGN   NB     ERR ERR  | TYPE_OP
** PARE    ERR     OP     OP     ERR    ERR END  | TYPE_NB
** ERR     PARB    ERR    SIGN   NB     ERR ERR  | TYPE_PARB
** PARE    ERR     OP     OP     ERR    ERR END  | TYPE_PARE
** ERR     PARB    ERR    ERR    NB     ERR ERR  | TYPE_SIGN
*/

void				free_tabs(t_pft **mtx, char *tok)
{
  int				idx;

  idx = -1;
  while (++idx < 6)
    free(mtx[idx]);
  free(mtx);
  free(tok);
}

t_pft				**parse_mtx(void)
{
  const t_pft			parse_mtx[6][7] =
    {
      {&p_e, &p_parb, &p_e, &p_sign, &p_nb, &p_e, &p_end},
      {&p_e, &p_parb, &p_e, &p_sign, &p_nb, &p_e, &p_e},
      {&p_pare, &p_e, &p_op, &p_op, &p_e, &p_e, &p_end},
      {&p_e, &p_parb, &p_e, &p_sign, &p_nb, &p_e, &p_e},
      {&p_pare, &p_e, &p_op, &p_op, &p_e, &p_e, &p_end},
      {&p_e, &p_parb, &p_e, &p_e, &p_nb, &p_e, &p_e},
    };
  t_pft				**prse_mtx_m;
  int				idx;

  idx = 6;
  if ((prse_mtx_m = malloc(sizeof(*prse_mtx_m) * 6)))
    {
      while (--idx > -1)
	{
	  if (!(prse_mtx_m[idx] = malloc(sizeof(**prse_mtx_m) * 7)))
	    return (NULL);
	  my_memcpy(prse_mtx_m[idx], parse_mtx[idx], 7 * sizeof(**prse_mtx_m));
	}
    }
  return (prse_mtx_m);
}

static void	set_tok_val(char *tok, char *ops, char *base, int idx)
{
  if (is_nb(idx, base) > -1)
    tok[idx] = NUM;
  else if (idx == ops[2])
    tok[idx] = ADD;
  else if (idx == ops[3])
    tok[idx] = SUB;
  else if (idx == ops[5])
    tok[idx] = DIV;
  else if (idx == ops[4])
    tok[idx] = MUL;
  else if (idx == ops[6])
    tok[idx] = MOD;
  else if (idx == ops[0])
    tok[idx] = PARB;
  else if (idx == ops[1])
    tok[idx] = PARE;
  else
    tok[(int)idx] = ERR;
}

char		*get_tok(char *base, char *ops)
{
  char		*tok;
  int		idx;

  if ((tok = malloc(sizeof(*tok) * 256)))
    {
      idx = -1;
      while (++idx < 256)
	set_tok_val(tok, ops, base, idx);
    }
  return (tok);
}
