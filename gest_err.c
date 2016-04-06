/*
** gest_err.c for  in /home/faure_k/github/sudoki-bi/sudoki-bi
** 
** Made by maxence faure
** Login   <faure_k@epitech.net>
** 
** Started on  Wed Apr  6 10:16:35 2016 maxence faure
** Last update Wed Apr  6 10:16:37 2016 maxence faure
*/

char *my_strcpy(char *dest, char *src)
{
  int i;

  i = 0;
  while(src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return dest;
}

char    **tabl()
{
  int   i;
  char  **tab;

  i = 0;
  tab = malloc(sizeof(char *) * 11);
  while (i < 11)
    {
      tab[i] = malloc(sizeof(char) * 20);
      i = i + 1;
    }
  my_strcpy(tab[0], "|------------------|");
  my_strcpy(tab[1], "| X X X X X X X X X|");
  my_strcpy(tab[2], "| X X X X X X X X X|");
  my_strcpy(tab[3], "| X X X X X X X X X|");
  my_strcpy(tab[4], "| X X X X X X X X X|");
  my_strcpy(tab[5], "| X X X X X X X X X|");
  my_strcpy(tab[6], "| X X X X X X X X X|");
  my_strcpy(tab[7], "| X X X X X X X X X|");
  my_strcpy(tab[8], "| X X X X X X X X X|");
  my_strcpy(tab[9], "| X X X X X X X X X|");
  my_strcpy(tab[10], "|------------------|");
  i = 0;
  while (i < 11)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (tab);
}
