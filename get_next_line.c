/*
** get_next_line.c for  in /home/faure_k/github/sudoki-bi/sudoki-bi
** 
** Made by maxence faure
** Login   <faure_k@epitech.net>
** 
** Started on  Wed Apr  6 10:13:49 2016 maxence faure
** Last update Wed Apr  6 10:13:50 2016 maxence faure
*/

#include	"include/sudoki-bi.h"
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

static char	*fill_str(char *str, int i, char *buffer, int *begin)
{
  char		*new_str;
  int		prev_length;

  prev_length = (str != NULL) ? strlen(str) : 0;
  new_str = xmalloc(prev_length + i + 1);
  if (str != NULL)
    strncpy(new_str, str, prev_length);
  strncpy(&new_str[prev_length], &buffer[*begin], i);
  new_str[prev_length + i] = '\0';
  *begin += i + 1;
  free(str);
  return (new_str);
}

char		*get_next_line(const int fd)
{
  char		*str;
  int		i;
  static char	buffer[BUFF_SIZE];
  static int	begin = 0;
  static int	buff_length = 0;

  str = NULL;
  i = 0;
  while (TRUE)
    {
      if (begin >= buff_length)
	{
	  if ((buff_length = xread(fd, buffer, BUFF_SIZE)) == 0)
	    return (str);
	  i = 0;
	  begin = 0;
	}
      if (buffer[begin + i] == '\n')
	return ((str = fill_str(str, i, buffer, &begin)));
      if (begin + i == buff_length - 1)
	str = fill_str(str, 1 + i, buffer, &begin);
      i++;
    }
}
