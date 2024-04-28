/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Main
*/

#include "LibHandler.hpp"
#include "Core.hpp"

int main(int ac, char *av[])
{
    Arcade::Core Core;

    if (ac != 2) {
        std::cerr << "Usage ./arcade [Starting Lib]" << std::endl;
        return 84;
    } else {
        Core.launchCore(av[1]);
    }
    return 0;
}