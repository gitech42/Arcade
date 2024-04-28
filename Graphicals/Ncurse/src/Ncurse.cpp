/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Sfml
*/

#include "Ncurse.hpp"

Arcade::Ncurse::Ncurse()
{
    _window = initscr();
    noecho();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    wbkgd(_window, COLOR_PAIR(1));
    attroff(COLOR_PAIR(1));

}

Arcade::Ncurse::~Ncurse()
{
    endwin();
}

extern "C" Arcade::IGraphicals *create()
{
    return (new Arcade::Ncurse());
}