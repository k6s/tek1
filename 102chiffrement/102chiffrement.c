/*
** main.c for 102chiffrement in /home/cano_c/rendu/MATHS/102chiffrement
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sun Nov 30 19:45:13 2014
** Last update Sun Nov 30 22:56:04 2014 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void		usage(void)
{
  printf("./102chiffrement message key base flag\nflag:\n\t1 => cypher\n\t0 => \
decypher\n");
}

char		*check_msg(char *argv)
{
  char		*p;

  p = argv;
  if (!*p)
    return (NULL);
  while (*p && ((isalpha(*p) && islower(*p)) || *p == ' '))
    ++p;
  if (*p)
    return (NULL);
  return (argv);
}

int		*get_msg(char *msg, size_t *msg_len)
{
  int		*msg_mtx;
  size_t	li;
  size_t	co;
  size_t	pli;

  *msg_len = strlen(msg);
  li = *msg_len / 2 + *msg_len % 2;
  co = 2;
  if ((msg_mtx = malloc(sizeof(*msg_mtx) * (li * co))))
    {
      pli = 0;
      while (pli < li)
	{
	  *(msg_mtx + pli * co + 1) = *msg == ' ' ? 0 : *msg - 'a' + 1;
	  ++msg;
	  if (*msg)
	    {
	      *(msg_mtx + pli * co) = *msg == ' ' ? 0 : *msg - 'a' + 1;
	      ++msg;
	    }
	  else
	    *(msg_mtx + pli * co) = 0;
	  ++pli;
	}
    }
  return (msg_mtx);
}

int		*mult_mtx(int *msg, int *key, size_t msg_len)
{
  size_t	li;
  size_t	co;
  int		*res;

  if ((res = malloc(sizeof(*res) * (msg_len + msg_len % 2))))
    {
      li = 0;
      while (li < msg_len / 2 + msg_len % 2)
	{
	  *(res + li * 2) = *(msg + li * 2) * key[1] + *(msg + li * 2 + 1)
	    * key[0];
	  *(res + li * 2 + 1) = *(msg + li * 2) * key[3] + *(msg + li * 2 + 1)
	    * key[2];
	  ++li;
	}
    }
  return (res);
}

int		get_base_idx(char *msg, char *base)
{
  size_t	idx;
  int		ret;
  size_t	base_len;

  base_len = strlen(base);
  ret = 0;
  while (*msg && *msg != ' ')
    {
      idx = 0;
      while (base[idx] && base[idx] != *msg)
	++idx;
      ret *= base_len;
      ret += idx;
      ++msg;
    }
  return (ret);
}

int		*get_hidden(char *msg, size_t *msg_len, char *base)
{
  int		*msg_mtx;
  size_t	li;
  size_t	co;
  size_t	pli;

  li = *msg_len / 2 + *msg_len % 2;
  co = 2;
  if ((msg_mtx = malloc(sizeof(*msg_mtx) * (li * co))))
    {
      pli = 0;
      while (pli < li && *msg)
	{
	  while (*msg == ' ')
	    ++msg;
	  if (*msg)
	    *(msg_mtx + pli * co + 1) = *msg == ' ' ? 0 : get_base_idx(msg, base);
	  else
	    *msg = 0;
	  while (*msg && *msg != ' ')
	    ++msg;
	  while (*msg && *msg == ' ')
	    ++msg;
	  if (*msg)
	      *(msg_mtx + pli * co) = *msg == ' ' ? 0 : get_base_idx(msg, base);
	  else
	    *(msg_mtx + pli * co) = 0;
	  while (*msg && *msg != ' ')
	    ++msg;
	  ++pli;
	}
    }
  *msg_len = pli * 2;
  return (msg_mtx);
}

int		*cypher(char *msg, int *key, int flag, char *base, size_t *msg_len)
{
  int		*res;
  int		*msg_mtx;

  res = NULL;
  if (!flag)
    msg_mtx = get_msg(msg, msg_len);
  else
    msg_mtx = get_hidden(msg, msg_len, base);
  if (msg_mtx)
    {
      res = mult_mtx(msg_mtx, key, *msg_len);
      free(msg_mtx);
    }
  else
    perror("./102chiffrement");
  return (res);
}

char		isnum(char *s)
{
  while (*s)
    {
      if (!isdigit(*s) && *s != '+' && *s != '-')
	return (0);
      ++s;
    }
  return (1);
}

char		get_key(char *c1, char *c2, char *c3, char *c4, int *key)
{
  if (isnum(c1) && isnum(c2) && isnum(c3) && isnum(c4))
    {
      key[0] = atoi(c1);
      key[2] = atoi(c2);
      key[1] = atoi(c3);
      key[3] = atoi(c4);
      if ((key[0] * key[3] - key[1] * key[2]))
	return (1);
    }
  return (0);
}

void		print_char_base(char c, char *base, size_t base_len)
{
  if (c >= base_len)
    print_char_base(c / base_len, base, base_len);
  write(1, &base[c % base_len], 1);
}

void		print_msg(char *msg, int *key, char *base, int *res, int flag,
			  size_t msg_len)
{
  size_t	li;
  size_t	base_len;
  char		*alpha = " abcdefghijklmnopqrstuvwxyz";

  if (flag)
    write(1, "de", 2);
  printf("chiffrement de \"%s\" a l'aide de la clef %d %d %d %d dans la base \"%s\"\n",
	 msg, key[0], key[2], key[1], key[3], base);
  write(1, " => ", 4);
  li = 0;
  if (flag)
    base = alpha;
  if ((base_len = strlen(base)) > 1)
    {
      while (li < msg_len / 2 + msg_len % 2)
	{
	  print_char_base(res[li * 2], base, base_len);
	  if (!flag)
	    write(1, " ", 1);
	  print_char_base(res[li * 2 + 1], base, base_len);
	  if (!flag)
	    write(1, " ", 1);
	  ++li;
	}
      printf("\n");
    }
  else
    printf("Invalid base\n");
}

void		inv_key(int *key)
{
  int		tmp;

  tmp = key[0];
  key[0] = key[3];
  key[3] = tmp;
  key[1] *= -1;
  key[2] *= -1;
}

char		*check_msg_base(char *msg, char *base)
{
  size_t	base_len;
  size_t	idx;
  char		*p_msg;

  if (!*msg)
    return (NULL);
  p_msg = msg;
  while (*msg)
    {
      if (*msg == ' ')
	++msg;
      else
	{
	  idx = 0;
	  while (base[idx] && *msg != base[idx])
	    ++idx;
	  if (!(base[idx]))
	    return (NULL);
	  ++msg;
	}
    }
  return (p_msg);
}

char		*check_base(char *base)
{
  char		tab[256] = {};
  char		*p_base;

  p_base = base;
  tab[' '] = 1;
  while (*base)
    {
      if (tab[*base])
	return (NULL);
      tab[*base] = 1;
      ++base;
    }
  if (base - p_base < 2)
    return (NULL);
  return (p_base);
}

int		main(int argc, char **argv)
{
  char		*msg;
  int		key[4];
  int		flag;
  int		*res;
  size_t	msg_len;

  if (argc == 8)
    {
      flag = atoi(argv[7]);
      if (check_base(argv[6]))
	{
	  if ((flag == 0 && (msg = check_msg(argv[1])))
	      || (flag == 1 && (msg = check_msg_base(argv[1], argv[6]))))
	    {
	      if (get_key(argv[2], argv[3], argv[4], argv[5], key))
		{
		  if (flag == 1)
		    inv_key(key);
		  res = cypher(msg, key, flag, argv[6], &msg_len);
		  if (flag)
		    inv_key(key);
		  print_msg(argv[1], key, argv[6], res, flag, msg_len);
		  free(res);
		  return (0);
		}
	    }
	}
      printf("Invalid args\n");
    }
  else
    usage();
  return (0);
}
