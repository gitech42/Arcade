##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
## File description:
## Makefile
##

SRC_DIR = src

CC		=	g++

LIB_PATH	=	../../lib

CXXFLAGS	+= -Wall -Wextra -W -g3

CPPFLAGS	=	-I./include -I./../include

NAME	=	arcade_pacman.so

SRC		=	src/Pacman.cpp

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):
			$(CC) $(CPPFLAGS) -fPIC -shared $(CXXFLAGS) $(SRC) -o $(NAME)
			mv $(NAME) $(LIB_PATH)/$(NAME)

clean:
	$(RM) $(LIB_PATH)/$(NAME)

fclean: clean
	$(RM) $(SRC_DIR)/*.o

re: clean fclean all
