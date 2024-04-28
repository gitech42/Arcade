/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Nibbler
*/

#ifndef Nibbler_HPP_
#define Nibbler_HPP_
#include "IGames.hpp"
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

namespace Arcade {
    class Nibbler : public IGames {
        public:
            Nibbler();
            ~Nibbler();
             void restart() {}
             void start(DIRECTION key) {
                move_nibbler(key);
            }
             void move(DIRECTION) {}
             int checkEnd() {
                if ((check_nb_snakegum()) == 0) {
                    return 1;
                }
                if ((check_loose_direction())) {
                    return 2;
                }
                return 0;
            }
            std::string openFiles(std::string file);
            std::vector<std::string> getMap() {return _map;};
            void stock_map();
            int my_strlenbis(std::string str);
            int nibbler_positiony();
            int my_get_line(std::string str);
            int nibbler_positionx();
            void move_right();
            void move_left();
            void move_up();
            void move_down();
            void move_nibbler(DIRECTION key);
            void delete_last();
            int last_tail_positiony();
            int last_tail_positionx();
            int check_nb_snakegum();
            int check_loose_direction();
            int check_nb_tail();

        protected:
        private:
            std::vector<std::string> _map;
            std::string _temp;
            int previous_snake_gum;
            int previous_tail_gum;
    };
}

#endif /* !Nibbler_HPP_ */
