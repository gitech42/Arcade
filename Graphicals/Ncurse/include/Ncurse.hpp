/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Ncurse
*/

#ifndef Ncurse_HPP_
#define Ncurse_HPP_

#include <curses.h>
#include <ncurses.h>
#include "IGraphicals.hpp"
#include "iostream"
#include "string"

namespace Arcade {
    class Ncurse : public IGraphicals {
        public:
            Ncurse();
            ~Ncurse();
            void refresh_w() {
                refresh();
            }
            void display_game(std::vector<Element_t> CoreGame) {
                clear();
                for (long unsigned int i = 0; i != CoreGame.size(); ++i) {
                    if (CoreGame[i].printable == true) {
                        mvprintw(CoreGame[i].pos_y + (LINES/2) - 9, CoreGame[i].pos_x + (COLS/2) - 20, CoreGame[i].name.c_str());
                    }
                }
            }
            void display_menu(std::vector<Element_t> menu, std::vector<Element_t> gameMenu) {
                clear();
                for (long unsigned int i = 0; i != menu.size(); ++i) {
                    if (menu[i].printable == true) {
                        if (menu[i].selected == true) {
                            attron(COLOR_PAIR(1));
                        } else {
                            attron(COLOR_PAIR(2));
                        }
                        mvprintw(i, 0, menu[i].name.c_str());
                    }
                }
                for (long unsigned int i = 0; i != gameMenu.size(); ++i) {
                    if (gameMenu[i].printable == true) {
                        if (gameMenu[i].selected == true) {
                            attron(COLOR_PAIR(1));
                        } else {
                            attron(COLOR_PAIR(2));
                        }
                        mvprintw(i + (LINES/2), (COLS/2) - 15, gameMenu[i].name.c_str());
                    }
                }
                attroff(COLOR_PAIR(1));
                attroff(COLOR_PAIR(2));
           }
            void display_score(std::vector<Element_t> score) {
                for (long unsigned int i = 0; i != score.size(); ++i) {
                    mvprintw(i, COLS - 20, score[i].name.c_str());
                    mvprintw(i, COLS - 10, (std::to_string(score[i].value)).c_str());
                }
            }
            Key listenEvent() {
                int input = 0;
                input = getch();
                if (input != -1) {
                    if (input == 0)
                        return Arcade::Key::Nothing;
                    if (input == 'Z')
                        return Arcade::Key::Z;
                    if (input == 'Q')
                        return Arcade::Key::Q;
                    if (input == 'S')
                        return Arcade::Key::S;
                    if (input == 'D')
                        return Arcade::Key::D;
                    if (input == 10)
                        return Arcade::Key::Enter;
                    if (input == KEY_LEFT)
                        return Arcade::Key::Left;
                    if (input == KEY_UP)
                        return Arcade::Key::Up;
                    if (input == KEY_DOWN)
                        return Arcade::Key::Down;
                    if (input == KEY_RIGHT)
                        return Arcade::Key::Right;
                    if (input == KEY_F(1))
                        return Arcade::Key::F1;
                    if (input == KEY_F(2))
                        return Arcade::Key::F2;
                    if (input == KEY_F(3))
                        return Arcade::Key::F3;
                    if (input == 'o' || input == 'O')
                        return Arcade::Key::F3;
                    if (input == 'i' || input == 'I')
                        return Arcade::Key::F2;
                    if (input == 'U' || input == 'u')
                        return Arcade::Key::F1;
                    if (input == 'P' || input == 'p')
                        return Arcade::Key::F4;
                    if (input == 'M' || input == 'm')
                        return Arcade::Key::M;
                    if (input == 27)
                        return Arcade::Key::End;
                }
                return Arcade::Key::Nothing;
            }
            void destroy() {
                refresh();
                endwin();
            }
        protected:
        private:
            WINDOW *_window;
    };
}
#endif /* !Ncurse_HPP_ */
