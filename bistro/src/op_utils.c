/*
** op_utils.c for Bistro in /home/cano_c/rendu/ELEM/Bistromathique
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Nov  7 16:47:54 2014
** Last update Sun Nov  9 15:43:55 2014 Cano Chloe
*/

#include <do-op.h>

void		add_one(t_nb *res, int pos, int base_len)
{
  res->nb[pos + 1] += 1;
  res->nb[pos] += res->nb[pos + 1] / base_len;
  res->nb[pos + 1] %= base_len;
  while (--pos >= 0)
    {
      res->nb[pos] += res->nb[pos + 1] / base_len;
      res->nb[pos + 1] %= base_len;
    }
}

void		sub_one(t_nb *res, int pos, int base_len)
{
  res->nb[pos + 1] -= 1;
  if (res->nb[pos + 1] < 0)
    {
      res->nb[pos + 1] += base_len;
      --res->nb[pos];
    }
  res->nb[pos] += res->nb[pos + 1] / base_len;
  res->nb[pos + 1] %= base_len;
  while (--pos >= 0)
    {
      if (res->nb[pos + 1] < 0)
	{
	  res->nb[pos + 1] += base_len;
	  --res->nb[pos];
	}
      res->nb[pos] += res->nb[pos + 1] / base_len ;
      res->nb[pos + 1] %= base_len;
    }
}

int		clean_res(t_nb *res, int max_len, char *base, char sign)
{
  char		*cleaned;
  int		pos;
  int		start;

  if (!(cleaned = malloc(sizeof(*cleaned) * (max_len))))
    return (0);
  my_bzero(cleaned, max_len);
  pos = -1;
  start = 0;
  if (res->sign)
    cleaned[start++] = sign;
  sign = res->sign ? 1 : 0;
  while (++pos < max_len)
    {
      if (res->nb[pos] || (start - sign))
	cleaned[start++] = base[(int)res->nb[pos]];
      else if (!(start - sign) && pos == max_len - 1)
	{
	  cleaned[start++ - sign] = base[0];
	  start -= sign;
	}
    }
  free(res->nb);
  res->nb = cleaned;
  return (start);
}

char		order_operands(t_nb **n1, t_nb **n2)
{
  t_nb		*tmp;

  if ((*n1)->len < (*n2)->len
      || (((*n1)->len == (*n2)->len && *(*n1)->nb < *(*n2)->nb)))
    {
      tmp = *n2;
      *n2 = *n1;
      *n1 = tmp;
      return (1);
    }
  return (0);
}

char		get_sign(t_nb *n1, t_nb *n2, char min)
{
  char		sign;

  sign = 0;
  if (*n1->nb == min)
    {
      sign |= 1;
      ++n1->nb;
      --n1->len;
    }
  if (*n2->nb == min)
    {
      sign |= 2;
      ++n2->nb;
      --n2->len;
    }
  return (sign);
}
