/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Sdl2
*/

#include "Sdl2.hpp"
#include <iostream>

Arcade::Sdl2::Sdl2()
{   
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        exit(EXIT_FAILURE);
    }
    if (TTF_Init() != 0) {
        exit(EXIT_FAILURE);
    }
    _window = SDL_CreateWindow("SDL --Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
    if (_window == nullptr) {
        exit(EXIT_FAILURE);
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == nullptr) {
        exit(EXIT_FAILURE);
    }
    _font = TTF_OpenFont("./assets/ARCADE_N.TTF", 14);
    _background = IMG_LoadTexture(_renderer, "./assets/background.jpg");
}

Arcade::Sdl2::~Sdl2()
{
    destroy();
}

extern "C" Arcade::IGraphicals *create()
{
    return (new Arcade::Sdl2());
}