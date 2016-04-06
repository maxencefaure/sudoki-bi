/*
** xtools.c for  in /home/faure_k/github/sudoki-bi/sudoki-bi
** 
** Made by maxence faure
** Login   <faure_k@epitech.net>
** 
** Started on  Wed Apr  6 10:16:02 2016 maxence faure
** Last update Wed Apr  6 10:16:03 2016 maxence faure
*/

#include	<unistd.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"include/sudoki-bi.h"

void		*xmalloc(size_t size)
{
  void		*str;

  if (!(str = malloc(size)))
    {
      my_puterror("Memory allocation failure - Exit\n");
      exit(EXIT_FAILURE);
    }
  return (str);
}

size_t		xread(int fd, char *buff, size_t count)
{
  int		nb_read;

  if ((nb_read = read(fd, buff, count)) == -1)
    {
      my_puterror("Read fail\n");
      exit(EXIT_FAILURE);
    }
  return ((size_t)nb_read);
}

size_t		xwrite(int fd, void *buff, size_t nbytes)
{
  int		nb_read;

  if ((nb_read = write(fd, buff, nbytes)) == -1)
    my_puterror("Can't write\n");
  return ((size_t)nb_read);
}
