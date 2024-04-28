##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
## File description:
## Makefile
##

all:	sfml ncurse sdl2

sfml:
	make -sC SFML/

ncurse:
	make -sC Ncurse/

sdl2:
	make -sC Sdl2/

clean:
	make -sC Ncurse/ clean
	make -sC SFML/ clean
	make -sC Sdl2/ clean

fclean: clean

re: fclean all
