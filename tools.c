/*
** tools.c for  in /home/faure_k/github/sudoki-bi/sudoki-bi
** 
** Made by maxence faure
** Login   <faure_k@epitech.net>
** 
** Started on  Wed Apr  6 10:14:31 2016 maxence faure
** Last update Wed Apr  6 10:14:32 2016 maxence faure
*/

#include	"include/sudoki-bi.h"
#include        <stdlib.h>
#include        <stdio.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str)
    while (str[i])
      i += 1;
  return (i);
}

void		my_putstr(char *str)
{
  xwrite(1, str, my_strlen(str));
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + 48);
}

void		my_puterror(char *str)
{
  xwrite(2, str, my_strlen(str));
}

void		my_putchar(char c)
{
  xwrite(1, &c, 1);
}
