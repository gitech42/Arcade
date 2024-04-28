SRC_DIR	=	src

SRC	=	src/main.cpp	\
		src/LibHandler.cpp	\
		src/Core.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	arcade

CC	=	g++

CXXFLAGS += -std=c++2a -Wall -Wextra -Werror -lncurses

CPPFLAGS	=	-Iinclude -I../Games/include -I../Graphicals/include  -I../Core/include

RM	=	rm -f

all:	$(NAME)

$(NAME):
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(NAME) $(SRC) -ldl
	mv $(NAME) ../$(NAME)

clean:
	$(RM) ../$(NAME)

fclean: clean
	$(RM) $(SRC_DIR)/*.o

re: clean fclean all
