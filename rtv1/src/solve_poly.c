/*
** solve_poly.c for rtv1 in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 23 13:53:20 2015
** Last update Sun Mar 15 16:11:45 2015 Cano Chloe
*/
#include <rtv1.h>

float		solve_poly_min(float a, float b, float c)
{
  float		delta;
  float		r1;
  float		r2;

  delta = pow(b, 2) - 4.00 * a * c;
  if (delta < 0)
    return (0);
  else if (!delta)
    return ((-1 * b) / (2 * a));
  else if (delta > 0)
    {
      r1 = (-1 * b - sqrt(delta)) / (2 * a);
      r2 = (-1 * b + sqrt(delta)) / (2 * a);
      if (r1 > 0 || r2 > 0)
	return (r1 > r2 ? r2 : r1);
      else
	return (0);
    }
  return (0);
}

int		solve_poly(float *s, float a, float b, float c)
{
  float		delta;

  delta = pow(b, 2) - 4.00 * a * c;
  if (delta < 0.001)
    return (0);
  else if (delta < 0.001 && !(s[1] = 0))
    {
      if ((s[0] = (-1 * b) / (2 * a)))
	return (1);
      return (0);
    }
  else if (delta > 0)
    {
      s[0] = (-1 * b - sqrt(delta)) / (2 * a);
      s[1] = (-1 * b + sqrt(delta)) / (2 * a);
      if (s[0] > 0 && s[1] > 0)
	return (2);
      if (s[0] > 0)
	return (1);
      if (s[1] <= 0)
	return (0);
      s[1] = s[0];
      return (1);
    }
  return (0);
}
