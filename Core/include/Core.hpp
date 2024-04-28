/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <map>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <dirent.h>
#include <string>
#include <dlfcn.h>
#include <vector>
#include "IGraphicals.hpp"
#include "IGames.hpp"
#include "LibHandler.hpp"

namespace Arcade {
    class Core {
        public:
            Core();
            ~Core();
            void getScore();
            void getGraphicalsLib();
            void getGamesLib();
            void addUserInScore(std::string &name);
            void writeFinalScore();
            void launchCore(const std::string &startingLib);
            void displayMenu();
            Arcade::IGames *handleMenuKey(Key c, std::vector<Element_t> &gameMenu, std::vector<Element_t> &graphicals, IGraphicals *(*graph));
            Arcade::Key handleGameKey(Key c, Arcade::IGames **currentGame, Arcade::IGraphicals **graph, std::vector<Element_t> &graphicals, std::vector<Element_t> &games);
        protected:
        private:
            Arcade::LibHandler _libGameHandler;
            Arcade::LibHandler _libGraphicHandler;
            std::vector<std::string> _graphicalsLib;
            std::vector <std::string> _gamesLib;
            std::map<std::string, int> _score;
            Key _lastDirection;
    };
}

#endif /* !CORE_HPP_ */
