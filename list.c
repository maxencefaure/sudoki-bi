/*
** list.c for  in /home/faure_k/github/sudoki-bi/sudoki-bi
** 
** Made by maxence faure
** Login   <faure_k@epitech.net>
** 
** Started on  Wed Apr  6 10:16:58 2016 maxence faure
** Last update Wed Apr  6 10:17:03 2016 maxence faure
*/

#include	"include/sudoki-bi.h"
#include        <stdlib.h>
#include        <stdio.h>

t_list		*end_add(t_list *list, int L, int C)
{
  t_list	*new;
  t_list	*temp;

  new = xmalloc(sizeof(t_list));
  new->val = xmalloc(10 * sizeof(*(new->val)));
  new->L = L;
  new->C = C;
  new->next = NULL;
  if (list == NULL)
    return (new);
  else
    {
      temp = list;
      while (temp->next != NULL)
	temp = temp->next;
      temp->next = new;
      return (list);
    }
}

t_list		*sort_list(t_list *nt)
{
  int		nb;
  int		n;

  nb = 1;
  n = 0;
  while (nb < 10)
    {
      nb++;
    }
  return (nt);
}

t_list		*algo_init(int **tab, t_list *nt)
{
  int		L;
  int		C;
  t_list	*last;

  C = 0;
  while (C < 9)
    {
      L = 0;
      while (L < 9)
	{
	  if (tab[C][L] == 0)
	    nt = end_add(nt, L, C);
	  L++;
	}
      C++;
    }
  return (nt);
}
