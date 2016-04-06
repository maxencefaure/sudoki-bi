/*
** sudoki-bi.h for  in /home/faure_k/github/sudoki-bi/sudoki-bi/include
** 
** Made by maxence faure
** Login   <faure_k@epitech.net>
** 
** Started on  Wed Apr  6 10:18:03 2016 maxence faure
** Last update Wed Apr  6 10:18:06 2016 maxence faure
*/

#ifndef		_SUDOKIBI_H_
# define	_SUDOKIBI_H_

# include	<stdlib.h>
# define	FALSE 0
# define	TRUE 1
# define	BUFF_SIZE 512

typedef struct	s_list
{
  int		L;
  int		C;
  char		*val;
  struct s_list	*next;
}		t_list;

typedef struct	s_square
{
  int		**grid;
  struct s_square *next;
}		t_square;

/* list.c */
t_list		*algo_init(int **tab, t_list *nt);
t_list		*end_add(t_list *list, int L, int C);

/* checkers.c */
int		fill_grid(t_list *begin, t_list *nt, int **grid);
void		case_updater(t_list *nt, int **grid);
int		line_column_checker(int nb, int **grid, int C, int L);
int		column_checker(int nb, int **grid, int L);
int		square_checker(int nb, int **grid, int L, int C);

/* get_next_line.c */
char		*get_next_line(const int fd);
static char	*fill_str(char *str,
			  int i,
			  char *buffer,
			  int *begin);

/* display_grid.c */
int		**malloc_tab(int **tab);
int		**display_grid(int **tab);
void		display_tab(int **tab);
void		free_tab(int **tab);

/* tools.c */
void		my_putnbr(int nb);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_puterror(char *str);
int		my_strlen(char *str);

/* xtools.c */
void		*xmalloc(size_t size);
size_t		xread(int fd, char *buff, size_t count);
size_t		xwrite(int fd, void *buff, size_t nbytes);

#endif		/* !_SUDOKI-BI_H_ */
