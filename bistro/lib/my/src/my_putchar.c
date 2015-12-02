/*
** my_putchar.c for my_putchar.c in /home/k6/rendu/Piscine_C_J07
** 
** Made by Cano Chloe
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Oct  8 15:14:22 2014 Cano Chloe
** Last update Sun Nov  9 13:19:03 2014 
*/

#include <my.h>

void			my_putchar(char c)
{
  write(1, &c, 1);
}
