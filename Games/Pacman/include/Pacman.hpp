/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_
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
    class Pacman : public IGames {
        public:
            Pacman();
            ~Pacman();
             void restart() {}
             void start(DIRECTION Key) {
                respawn_pacman();
                move_pacman(Key);
                respawn_ghost();
                move_ghost();
            }
             void move(DIRECTION) {}
             std::vector<std::string> getMap() {return _map;};
            void move_pacman(DIRECTION key);
            void stock_map();
             int checkEnd() {
                std::string temp = openFiles("./Games/Pacman/pacman_map.txt");
                int col = my_strlenbis(temp);
                int lines = my_get_line(temp);
                int stock = 0;

                for (int i = 0; i != lines; ++i) {
                    for (int j = 0; j != col; ++j)
                        if (_map[i][j] ==  'o')
                            stock++;
                }
                if (stock == 0)
                     return 1;
                if (pacman_positionx() == 0 &&  pacman_positiony() == 0)
                    return 2;
                return 0;
            }
            int pacman_positiony();
            int pacman_positionx();
            void move_up();
            void move_down();
            void move_right();
            void move_left();
            std::string openFiles(std::string file);
            int my_get_line(std::string str);
            int my_strlenbis(std::string tmp);
            void move_ghost_to_capture(char ghost);
            void move_ghost_to_runaway(char ghost);
            void move_ghost();
            int fghost_positiony(char ghost);
            int fghost_positionx(char ghost);
            void respawn_pacman();
            int check_nb_pacgum();
            int check_is_eat(char ghost);
            int respawn_ghost();
            std::vector<std::string> _map;

        protected:
            int _time;
            bool ghost_is_eatable;
            std::string _temp;
            int time_to_eat_ghost;
            int previous_pac_gum;
        private:
    };
}

#endif /* !PACMAN_HPP_ */
