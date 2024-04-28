/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** LibHandler
*/

#include "LibHandler.hpp"
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <dirent.h>
#include <string>
#include <dlfcn.h>

Arcade::LibHandler::LibHandler()
: _buffer(nullptr), _addr(nullptr)
{
}

Arcade::LibHandler::~LibHandler()
{
}

bool Arcade::LibHandler::openLib(const std::string &filename)
{
    _buffer = dlopen(filename.c_str(), RTLD_LAZY);
    if (!_buffer) {
        std::cout << "Error openLib(): " << dlerror() << std::endl;
        _buffer = nullptr;
        return false;
    }
    return true;
}

void Arcade::LibHandler::closeLib()
{
    if (_buffer)
        if (dlclose(_buffer))
            std::cout << "Error: closeLib() : " << dlerror() << std::endl;
}

void *Arcade::LibHandler::getFunctionFromLib(const std::string& func)
{
    void *function = NULL;

    if (_buffer) {
        function = dlsym(_buffer, func.c_str());
        if (!function) {
            std::cout << "Error: getFunctionFromLib(): " << dlerror() << std::endl;
            return NULL;
        }
    }
    if (!function) {
        std::cout << "Cannot get function: " << func << std::endl;
    }
    return function;
}