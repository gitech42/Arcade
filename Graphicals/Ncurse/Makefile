##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
## File description:
## Makefile
##

SRC_DIR = src

LIB_PATH	=	../../lib

CC		=	g++

CXXFLAGS	+=	 -Wall -Wextra -W -g3 -fPIC

CPPFLAGS	=	-I./include -I./../include

NAME	=	arcade_ncurses.so

SRC		=	src/Ncurse.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)


$(NAME):
			$(CC) $(CPPFLAGS) -shared $(CXXFLAGS) $(SRC) -o $(NAME) -lncurses
			mv $(NAME) $(LIB_PATH)/$(NAME)

clean:
	$(RM) $(LIB_PATH)/$(NAME)

fclean: clean
	$(RM) $(SRC_DIR)/*.o

re: clean fclean all
