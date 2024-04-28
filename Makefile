##
## EPITECH PROJECT, 2022
## B-OOP-400-PAR-4-1-tekspice-bilel.barkallah
## File description:
## Makefile
##

all:	core graphicals games

core:
	make -sC Core/

graphicals:
	make -sC Graphicals/

games:
	make -sC Games/

clean:
	make -sC Core/ clean
	make -sC Graphicals/ clean
	make -sC Games/ clean

fclean: clean

re: fclean all