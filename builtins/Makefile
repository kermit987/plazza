##
## Makefile for plazza in /home/sayavo_f/Desktop/builtins
##
## Made by sayavong frederic
## Login   <sayavo_f@epitech.net>
##
## Started on  Wed Apr 20 17:49:28 2016 sayavong frederic
## Last update Thu Apr 21 03:22:15 2016 sayavong frederic
##

CC	= g++

NAME	= builtins

CPPFLAGS	+= -W -Wall -Werror -Wextra
CPPFLAGS	+= -I./includes

SRCS	= srcs/main.cpp \
	  srcs/InvalidPath.cpp \
	  srcs/LS.cpp \
	  srcs/Chdir_dir.cpp

OBJS	= $(SRCS:.cpp=.o)

RM	= rm -f
PRINTF	= @printf

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(PRINTF) '\033[1;32m> Compiled\033[0m\n'

clean:
	$(RM) $(OBJS)
	$(PRINTF) '\033[1;35m> Directory cleaned\033[0m\n'

fclean: clean
	$(RM) $(NAME)
	$(PRINTF) '\033[1;35m> Remove executable\033[0m\n'

re: fclean all

.PHONY: all clean fclean re
