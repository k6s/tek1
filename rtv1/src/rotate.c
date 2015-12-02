/*
** rotate.c for rtv1.h in /home/cano_c/rendu/IGRAPH/MUL_2014_rtv1
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Feb 23 13:51:15 2015
** Last update Sun Mar 15 16:11:09 2015 Cano Chloe
*/
#include <rtv1.h>

void		rotate_z(t_3dpoint *point, float a)
{
  float		mtx[3][3];

  mtx[0][0] = cos(a);
  mtx[0][1] = -1.00 * sin(a);
  mtx[0][2] = 0;
  mtx[1][0] = sin(a);
  mtx[1][1] = cos(a);
  mtx[1][2] = 0;
  mtx[2][0] = 0;
  mtx[2][1] = 0;
  mtx[2][2] = 1;
  mult_mtx(mtx, point);
}

void		rotate_y(t_3dpoint *point, float a)
{
  float		mtx[3][3];

  mtx[0][0] = cos(a);
  mtx[0][1] = 0;
  mtx[0][2] = sin(a);
  mtx[1][0] = 0;
  mtx[1][1] = 1;
  mtx[1][2] = 0;
  mtx[2][0] = -1.00 * sin(a);
  mtx[2][1] = 0;
  mtx[2][2] = cos(a);
  mult_mtx(mtx, point);
}

void		rotate_x(t_3dpoint *point, float a)
{
  float		mtx[3][3];

  mtx[0][0] = 1;
  mtx[0][1] = 0;
  mtx[0][2] = 0;
  mtx[1][0] = 0;
  mtx[1][1] = cos(a);
  mtx[1][2] = -1.00 * sin(a);
  mtx[2][0] = 0;
  mtx[2][1] = sin(a);
  mtx[2][2] = cos(a);
  mult_mtx(mtx, point);
}
