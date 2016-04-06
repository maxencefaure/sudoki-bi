/*
** main.c for  in /home/faure_k/github/sudoki-bi/sudoki-bi
** 
** Made by maxence faure
** Login   <faure_k@epitech.net>
** 
** Started on  Wed Apr  6 10:14:10 2016 maxence faure
** Last update Wed Apr  6 10:14:11 2016 maxence faure
*/

#include	"include/sudoki-bi.h"
#include        <stdlib.h>
#include        <stdio.h>

void		free_list(t_list *list)
{
  t_list	*tmp;

  if (list)
    while (list)
      {
	free(list->val);
	tmp = list;
	free(tmp);
	list = list->next;
      }
}

t_square	*add_grid(t_square *list, int **grid)
{
  t_square	*new;
  t_square	*temp;

  new = xmalloc(sizeof(t_list));
  new->grid = grid;
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

void		aff_and_free(t_square *sq)
{
  int		loop;
  t_square	*tmp;

  loop = 0;
  while (sq != NULL)
    {
      if (loop)
	my_putstr("####################\n");
      display_tab(sq->grid);
      free_tab(sq->grid);
      tmp = sq;
      sq = sq->next;
      free(tmp);
      loop++;
    }
}

int		main()
{
  char		*s;
  int		**tab;
  t_square	*sq;
  t_list	*nt;

  sq = NULL;
  while (s = get_next_line(0))
    {
      nt = NULL;
      free(s);
      tab = malloc_tab(tab);
      tab = display_grid(tab);
      sq = add_grid(sq, tab);
      nt = algo_init(tab, nt);
      case_updater(nt, tab);
      fill_grid(nt, nt, tab);
      free_list(nt);
    }
  aff_and_free(sq);
  return (0);
}
