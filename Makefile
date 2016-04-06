##
## Makefile for  in /home/faure_k/github/sudoki-bi/sudoki-bi
## 
## Made by maxence faure
## Login   <faure_k@epitech.net>
## 
## Started on  Wed Apr  6 10:15:40 2016 maxence faure
## Last update Wed Apr  6 10:15:42 2016 maxence faure
##

NAME		= 	sudoki-bi

DIR		=	/home/faure_k/b2/elementaire/sudoki-bi/bin

SRCS		= 	main.c			\
			list.c			\
			display_grid.c		\
			checkers.c		\
			get_next_line.c		\
			tools.c			\
			xtools.c


OBJS		= 	$(SRCS:.c=.o)

CFLAGS		+=	-W -Wextra -ansi -pedantic -O3

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(DIR)/$(NAME)
			@echo -e "Your program compiled successfully"

clean:
			rm -f $(OBJS)
			@echo -e "Your repository has been cleaned"

fclean:			clean
			rm -f $(DIR)/sudoki-bi

re:			fclean all

.PHONY:			all clean fclean re
