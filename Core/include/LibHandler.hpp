/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** LibHandler
*/

#ifndef LIBHANDLER_HPP_
#define LIBHANDLER_HPP_

#include "string.h"
#include <dlfcn.h>
#include "iostream"

namespace Arcade {
    class LibHandler {
        public:
            LibHandler();
            ~LibHandler();
            bool openLib(const std::string &filename);
            void *getFunctionFromLib(const std::string &func);
            void closeLib();
        protected:
            void *_buffer;
            void *_addr;
        private:
    };
}

#endif /* !LIBHANDLER_HPP_ */
