/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_
#include "iostream"
#include "vector"

namespace Arcade {
    enum DIRECTION {
        NOTHING,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    class IGames {
        public:
            virtual ~IGames() = default;
            virtual void restart() = 0;
            virtual void start(DIRECTION key) = 0;
            virtual void move(DIRECTION) = 0;
            virtual int checkEnd() = 0;
            virtual std::vector<std::string> getMap() = 0;
        protected:
        private:
    };
}

typedef Arcade::IGames *createGames(void);

#endif /* !IGAMES_HPP_ */