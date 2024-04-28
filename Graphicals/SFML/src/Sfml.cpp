/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Sfml
*/

#include "Sfml.hpp"
#include <iostream>

Arcade::Sfml::Sfml()
{
    _window = new sf::RenderWindow({1920, 1080}, "Arcade", sf::Style::Close | sf::Style::Resize);
    _window->setFramerateLimit(30);
}

Arcade::Sfml::~Sfml()
{
    delete _window;
}

extern "C" Arcade::IGraphicals *create()
{
    return (new Arcade::Sfml());
}