/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** IGraphicals
*/

#ifndef IGRAPHICALS_HPP_
#define IGRAPHICALS_HPP_
#include "string"
#include "vector"

namespace Arcade {
    enum Key {
        F9,
        Up,
        Down,
        Left,
        Right,
        Z,
        Q,
        S,
        D,
        P,
        U,
        X,
        O,
        Nothing,
        Space,
        Enter,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        M,
        End
    };

    typedef struct Element_s {
        std::string name;
        std::string texturePath;
        float pos_x;
        float pos_y;
        bool printable;
        bool isPrint;
        bool selected;
        int value;
        int size;

    } Element_t;
    class IGraphicals {
        public:
           virtual ~IGraphicals() = default;
           virtual void refresh_w() = 0;
           virtual void display_game(std::vector<Element_t> CoreGame) = 0;
           virtual void display_menu(std::vector<Element_t> menu, std::vector<Element_t> gameMenu) = 0;
           virtual void display_score(std::vector<Element_t> score) = 0;
           virtual Key listenEvent() = 0;
           virtual void destroy() = 0;

        protected:
        private:
    };
}
typedef Arcade::IGraphicals *createGraphicals(void);

#endif /* !IGRAPHICALS_HPP_ */
