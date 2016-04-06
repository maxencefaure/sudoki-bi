/*
** display_grid.c for  in /home/faure_k/github/sudoki-bi/sudoki-bi
** 
** Made by maxence faure
** Login   <faure_k@epitech.net>
** 
** Started on  Wed Apr  6 10:14:56 2016 maxence faure
** Last update Wed Apr  6 10:14:57 2016 maxence faure
*/

#include	"include/sudoki-bi.h"
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>

int		**display_grid(int **tab)
{
  char		*s;
  int		i;
  int		j;
  int		k;

  j = 0;
  while (j < 9)
    {
      k = 0;
      i = 2;
      s = get_next_line(0);
      while (k < 9)
	{
	  if (s && s[i] >= '1' && s[i] <= '9')
	    tab[j][k] = s[i] - '0';
	  else if (s && s[i] == ' ')
	    tab[j][k] = 0;
	  k++;
	  i = i + 2;
	}
      j++;
    }
  s = get_next_line(0);
  free(s);
  return (tab);
}

void		display_tab(int **tab)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  my_putstr("|------------------|\n");
  while (tab && j < 9)
    {
      my_putchar('|');
      while (i < 9)
	{
	  my_putchar(' ');
	  my_putnbr(tab[j][i]);
	  i++;
	}
      i = 0;
      j++;
      my_putchar('|');
      my_putchar('\n');
    }
  my_putstr("|------------------|\n");
}

int		**malloc_tab(int **tab)
{
  int		i;

  i = 0;
  tab = xmalloc(9 * sizeof(*tab));
  while (i < 9)
    {
      tab[i] = xmalloc(9 * sizeof(**tab));
      memset(tab[i], '\0', 10);
      i++;
    }
  return (tab);
}

void		free_tab(int **tab)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
