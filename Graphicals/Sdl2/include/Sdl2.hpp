/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Sdl2
*/

#ifndef Sdl2_HPP_
#define Sdl2_HPP_

#include "IGraphicals.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

namespace Arcade {
    class Sdl2 : public IGraphicals {
        public:
            Sdl2();
            ~Sdl2();

            void refresh_w() 
            {
                SDL_RenderPresent(_renderer);
                SDL_RenderCopy(_renderer, _background, nullptr, nullptr);
            }

            void display_menu(std::vector<Element_t> menu, std::vector<Element_t> gameMenu)
            {
                SDL_Texture *_txt_menu = nullptr;
                SDL_Surface *_text_gameMenu = nullptr;
                SDL_Texture *_txt_gameMenu = nullptr;
                SDL_Surface *_text = nullptr;
                SDL_Rect position;
                position = {0, 0, 0, 0};
                SDL_Rect position_gameMenu;
                position_gameMenu = {0, 0, 0, 0};
                
                for (long unsigned int i = 0; i != menu.size(); ++i) {
                    if (menu[i].printable == true) {
                        if(menu[i].selected == true) {
                            _text = TTF_RenderText_Blended(_font, menu[i].name.c_str(), SDL_Color{0, 128, 0, 0});
                        } else {
                            _text = TTF_RenderText_Blended(_font, menu[i].name.c_str(), SDL_Color{0,255,0,255});
                        }
                        _txt_menu = SDL_CreateTextureFromSurface(_renderer, _text);
                        position.x = 250;
                        position.y = (80 + i * 40);
                        SDL_QueryTexture(_txt_menu, nullptr, nullptr, &position.w, &position.h);
                        SDL_RenderCopy(_renderer, _txt_menu, nullptr, &position);
                        SDL_DestroyTexture(_txt_menu);
                        SDL_FreeSurface(_text);
                    }
                }
                for (long unsigned int i = 0; i != gameMenu.size(); ++i) 
                {
                    if (gameMenu[i].printable == true) {
                        if (gameMenu[i].selected == true) {
                            _text_gameMenu = TTF_RenderText_Blended(_font, gameMenu[i].name.c_str(), SDL_Color{0,128,0,0});
                        } else {
                            _text_gameMenu = TTF_RenderText_Blended(_font, gameMenu[i].name.c_str(), SDL_Color{0,255,0,255});
                        }
                        _txt_gameMenu = SDL_CreateTextureFromSurface(_renderer, _text_gameMenu);
                        position_gameMenu.x = 800;
                        position_gameMenu.y = (600 + i * 40);
                        SDL_QueryTexture(_txt_gameMenu, nullptr, nullptr, &position_gameMenu.w, &position_gameMenu.h);
                        SDL_RenderCopy(_renderer, _txt_gameMenu, nullptr, &position_gameMenu);
                        SDL_DestroyTexture(_txt_gameMenu);
                        SDL_FreeSurface(_text_gameMenu);
                    }
                }

            }
            
            void display_game(std::vector<Element_t> CoreGame) 
            {
                SDL_Rect _posi_game = {0, 0, 0, 0};
                SDL_Texture *_text_game = nullptr;
                
                SDL_RenderClear(_renderer);
                for (long unsigned int i = 0; i != CoreGame.size(); ++i) {
                    if (CoreGame[i].name == "" && i + 1 < CoreGame.size()) {
                        continue;
                    } else if (CoreGame[i].name == "") {
                        return;
                    }
                    _posi_game.x = (CoreGame[i].pos_x * 35 + 300);
                    _posi_game.y = (CoreGame[i].pos_y * 35 + 150);
                    _text_game = IMG_LoadTexture(_renderer, CoreGame[i].texturePath.c_str());
                    SDL_QueryTexture(_text_game, nullptr, nullptr, &_posi_game.w, &_posi_game.h);
                    SDL_RenderCopy(_renderer, _text_game, nullptr, &_posi_game);
                    SDL_DestroyTexture(_text_game);
                }
            }
            
            void display_score(std::vector<Element_t> score) 
            {
                SDL_Surface *_text = nullptr;
                SDL_Texture *_txt_score = nullptr;
                SDL_Rect position = {0, 0, 0, 0};

                for (long unsigned int i = 0; i != score.size(); ++i) {
                    if (score[i].printable == true) {
                        std::string _init = score[i].name;
                        std::string _score = std::to_string(score[i].value);
                        std::string _new_score = _init + ":  " + _score;
                        const char* score = _new_score.c_str();
                        _text = TTF_RenderText_Blended(_font, score, SDL_Color{0,128,0,0});                
                    }
                    _txt_score = SDL_CreateTextureFromSurface(_renderer, _text);
                    position.x = 1500;
                    position.y = (50 * i + 50);
                    SDL_QueryTexture(_txt_score, nullptr, nullptr, &position.w, &position.h);
                    SDL_RenderCopy(_renderer, _txt_score, nullptr, &position);
                    SDL_DestroyTexture(_txt_score);
                    SDL_FreeSurface(_text);
                }
            }
            
            void destroy() 
            {
                TTF_CloseFont(_font);
                SDL_DestroyRenderer(_renderer);
                SDL_DestroyWindow(_window);
            }

            Key listenEvent() 
            {
                SDL_Event _events;

                while (SDL_PollEvent(&_events)) {
                    switch(_events.type) {
                        case SDL_WINDOWEVENT:
                            if (_events.window.event == SDL_WINDOWEVENT_CLOSE) {
                                return Arcade::End;
                            }
                            break;
                        case SDL_KEYDOWN:
                            if (_events.key.keysym.sym == SDLK_ESCAPE) {
                                return Arcade::End;
                            }
                            if (_events.key.keysym.sym == SDLK_p) {
                                return Arcade::P;
                            }
                            if (_events.key.keysym.sym == SDLK_u) {
                                return Arcade::U;
                            }
                            if (_events.key.keysym.sym == SDLK_x) {
                                return Arcade::X;
                            }
                            if (_events.key.keysym.sym == SDLK_o) {
                                return Arcade::O;
                            }
                            if (_events.key.keysym.sym == SDLK_UP) {
                                return Arcade::Up;
                            }
                            if (_events.key.keysym.sym == SDLK_DOWN) {
                                return Arcade::Down;
                            }
                            if (_events.key.keysym.sym == SDLK_LEFT) {
                                return Arcade::Left;
                            }
                            if (_events.key.keysym.sym == SDLK_RIGHT) {
                                return Arcade::Right;
                            }
                            if (_events.key.keysym.sym == SDLK_F1) {
                                return Arcade::F1;
                            }
                            if (_events.key.keysym.sym == SDLK_F2) {
                                return Arcade::F2;
                            }
                            if (_events.key.keysym.sym == SDLK_F3) {
                                return Arcade::F3;
                            }
                            if (_events.key.keysym.sym == SDLK_F4) {
                                return Arcade::F4;
                            }
                            if (_events.key.keysym.sym == SDLK_z) {
                                return Arcade::Z;
                            }
                            if (_events.key.keysym.sym == SDLK_q) {
                                return Arcade::Q;
                            }
                            if (_events.key.keysym.sym == SDLK_s) {
                                return Arcade::S;
                            }
                            if (_events.key.keysym.sym == SDLK_d) {
                                return Arcade::D;
                            }
                            if (_events.key.keysym.sym == SDLK_RETURN) {
                                return Arcade::Enter;
                            }
                            if (_events.key.keysym.sym == SDLK_m) {
                                return Arcade::M;
                            }
                            break;
                    }
                }
            return Arcade::Nothing;
            }

            void clearwindow() {
                SDL_RenderClear(_renderer);
            }
        protected:
        private:
            SDL_Renderer *_renderer;
            TTF_Font *_font;
            SDL_Window *_window;
            SDL_Texture *_background;
    };
}
#endif /* !Sdl2_HPP_ */
