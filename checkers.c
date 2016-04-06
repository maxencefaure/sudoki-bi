/*
** checkers.c for  in /home/faure_k/github/sudoki-bi/sudoki-bi
** 
** Made by maxence faure
** Login   <faure_k@epitech.net>
** 
** Started on  Wed Apr  6 10:13:11 2016 maxence faure
** Last update Wed Apr  6 10:13:12 2016 maxence faure
*/

#include	"include/sudoki-bi.h"
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>

int		square_checker(int nb, int **grid, int L, int C)
{
  int		j;
  int		i;
  int		tmp;

  j = C-(C%3);
  i = L-(L%3);
  L = i + 3;
  C = j + 3;
  tmp = i;
  while (j < C)
    {
      i = tmp;
      while (i < L)
	{
	  if (grid[j][i] == nb)
	    return (0);
	  i++;
	}
      j++;
    }
  return (1);
}

int		line_column_checker(int nb, int **grid, int C, int L)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      if (grid[C][i] == nb)
	return (0);
      i++;
    }
  i = 0;
  while (i < 9)
    {
      if (grid[i][L] == nb)
	return (0);
      i++;
    }
  return (1);
}

void		case_updater(t_list *nt, int **grid)
{
  int		i;

  if (nt)
    while (nt)
      {
	i = 1;
	memset(nt->val, 0, 10);
	while (i < 10)
	  {
	    if (line_column_checker(i, grid, nt->C, nt->L) == 1 &&
		square_checker(i, grid, nt->L, nt->C) == 1)
	      nt->val[i] = 1;
	    i++;
	  }
	nt = nt->next;
      }
}

int		fill_grid(t_list *begin, t_list *nt, int **grid)
{
  int		i;

  i = 1;
  if (!nt)
    return (1);
  while (i < 10)
    {
      if (nt->val[i] == 1)
	{
	  grid[nt->C][nt->L] = i;
	  case_updater(nt, grid);
	  if (fill_grid(nt, nt->next, grid) == 1)
	    return (1);
	  grid[nt->C][nt->L] = 0;
	  case_updater(nt, grid);
	}
      i++;
    }
  return (0);
}
