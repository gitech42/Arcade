/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "IGraphicals.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "iostream"

namespace Arcade {
    class Sfml : public IGraphicals {
        public:
            Sfml();
            ~Sfml();

            void refresh_w() {
                _window->display();
                _window->clear();
            }
            void display_menu(std::vector<Element_t> menu, std::vector<Element_t> gameMenu) {
                sf::Text text;
                sf::Sprite bkg;
                sf::Texture t;
                sf::Font f;

                t.loadFromFile("./assets/background.jpg");
                bkg.setTexture(t);
                f.loadFromFile("./assets/ARCADE_N.TTF");
                text.setFont(f);
                text.setCharacterSize(14);
                text.setFillColor(sf::Color::White);
                bkg.setScale(1,1);
                bkg.setPosition(0, 0);
                _window->draw(bkg);
                
                for (long unsigned int i = 0; i != menu.size(); ++i)
                    if (menu[i].printable == true) {
                        if (menu[i].selected == true) {
                            text.setFillColor(sf::Color::Red);
                        } else
                            text.setFillColor(sf::Color::White);
                        text.setPosition(250, 80 + i * 40);
                        text.setString(menu[i].name);
                        _window->draw(text);
                    }
                for (long unsigned int i = 0; i != gameMenu.size(); ++i) {
                    if (gameMenu[i].printable == true) {
                        text.setPosition(800, 600 + i * 40);
                        text.setString(gameMenu[i].name);
                        if (gameMenu[i].selected == true) {
                            text.setFillColor(sf::Color::Blue);
                        } else
                            text.setFillColor(sf::Color::White);
                        _window->draw(text);
                    }
                }
           }

            void display_game(std::vector<Element_t> CoreGame) {
                sf::Sprite sprite;
                sf::Texture t;

                for (long unsigned int i = 0; i != CoreGame.size(); ++i ) {
                    if (CoreGame[i].name == "" && i + 1 < CoreGame.size())
                        continue;
                    else if (CoreGame[i].name == "")
                        return;
                    t.loadFromFile(CoreGame[i].texturePath);
                    sprite.setTexture(t);
                    sprite.setPosition((CoreGame[i].pos_x * 38 + 450), (CoreGame[i].pos_y * 33 + 120));
                    sprite.setScale(1, 1);
                    _window->draw(sprite);
                }
            }
            void display_score(std::vector<Element_t> score) {
                sf::Text text;
                sf::Font f;
                f.loadFromFile("./assets/ARCADE_N.TTF");
                text.setFont(f);
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::White);

                for (long unsigned int i = 0; i != score.size(); ++i)
                    if (score[i].printable == true) {
                        text.setPosition(1500, 50 * i + 50);
                        text.setString(score[i].name + ": " + std::to_string(score[i].value));
                        _window->draw(text);
                }
            }

            Key listenEvent() {
                sf::Event event;

                while (_window->pollEvent(event)) {
                    if (event.type == sf::Event::KeyReleased) {
                        if (event.key.code == sf::Keyboard::Escape)
                            return Arcade::End;
                        if (event.key.code == sf::Keyboard::P)
                            return Arcade::P;
                        if (event.key.code == sf::Keyboard::U)
                            return Arcade::U;
                        if (event.key.code == sf::Keyboard::X)
                            return Arcade::X;
                        if (event.key.code == sf::Keyboard::O)
                            return Arcade::O;
                        if (event.key.code == sf::Keyboard::Up)
                            return Arcade::Up;
                        if (event.key.code == sf::Keyboard::Down)
                            return Arcade::Down;
                        if (event.key.code == sf::Keyboard::Left)
                            return Arcade::Left;
                        if (event.key.code == sf::Keyboard::Right)
                            return Arcade::Right;
                        if (event.key.code == sf::Keyboard::F1)
                            return Arcade::F1;
                        if (event.key.code == sf::Keyboard::F2)
                            return Arcade::F2;
                        if (event.key.code == sf::Keyboard::F3)
                            return Arcade::F3;
                        if (event.key.code == sf::Keyboard::F4)
                            return Arcade::F4;
                        if (event.key.code == sf::Keyboard::Z)
                            return Arcade::Z;
                        if (event.key.code == sf::Keyboard::Q)
                            return Arcade::Q;
                        if (event.key.code == sf::Keyboard::S)
                            return Arcade::S;
                        if (event.key.code == sf::Keyboard::D)
                            return Arcade::D;
                        if (event.key.code == sf::Keyboard::Enter)
                            return Arcade::Enter;
                        if (event.key.code == sf::Keyboard::M)
                            return Arcade::M;
                    }
                }
                return Arcade::Nothing;

            }
            void destroy() {
                    _window->close();
                    delete _window;
                }

        protected:
        private:
            sf::RenderWindow *_window;
    };
}
#endif /* !SFML_HPP_ */
