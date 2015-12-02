/*
** print_ll.c for printf in /home/k6/rendu/PSU_2014_my_printf
** 
** Made by Cano Chloe
** Login   <k6@epitech.net>
** 
** Started on  Sun Nov 16 20:23:54 2014 Cano Chloe
** Last update Sun Nov 16 22:31:22 2014 
*/

#include <my.h>
#include <limits.h>

static int	put_unsigned(unsigned long long var, unsigned int base_len)
{
  int		ret;

  ret = 0;
  if (var >= base_len)
    ret = put_unsigned(var / base_len, base_len);
  my_putchar(var % base_len + '0');
  return (ret + 1);
}

static int	put_signed(signed long long var, int base_len)
{
  int		ret;

  ret = 0;
  if (var < 0)
    {
      if (var == LLONG_MIN)
	{
	  put_signed(var / base_len * -1, base_len);
       	  put_signed(var % base_len * -1, base_len);
	}
      else
	{
	  my_putchar('-');
	  var *= -1;
	}
    }
  if (var >= base_len)
    ret = put_signed(var / base_len, base_len);
  if ((var % base_len + '0') != '(')
  my_putchar(var % base_len + '0');
  return (ret + 1);
}

int		put_ll_reg(t_types *var, char conv, int base_len)
{
  if (conv == 'i' || conv == 'd')
    {
      var->lls = (signed long long)var->lls;
      return (put_signed(var->lls, base_len));
    }
  else if (conv == 'u' || conv == 'o')
    return (put_unsigned((unsigned long long)var->lls, base_len));
  return (-1);
}

static int	put_unsigned_base(unsigned long long var, char *base,
				  unsigned int base_len)
{
  int		ret;

  ret = 0;
  if (var >= base_len)
    ret = put_unsigned_base(var / base_len, base, base_len);
  my_putchar(base[var % base_len]);
  return (ret + 1);
}

int		put_ll_base(t_types *var, char *base, unsigned int base_len)
{
  return (put_unsigned_base(var->llu, base, base_len));
}
