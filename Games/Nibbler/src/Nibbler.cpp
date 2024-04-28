/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include "iostream"

Arcade::Nibbler::Nibbler() : previous_snake_gum(28), previous_tail_gum(0)
{
    _temp = openFiles("./Games/Nibbler/nibbler_map.txt");
    stock_map();
}

Arcade::Nibbler::~Nibbler()
{
    _map.clear();
    _temp.clear();
}

std::string Arcade::Nibbler::openFiles(std::string file)
{
    std::stringstream buffer;
    std::ifstream score_file(file);

    if (score_file.is_open() == false)
        std::cout << "Error openFile: File is not readable" << std::endl;
    else if (score_file.is_open()) {
        buffer << score_file.rdbuf();
    }
    std::string str = buffer.str();
    score_file.close();
    return str;
}

int Arcade::Nibbler::my_get_line(std::string str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '\n')
            j++;
    return j;
}

void Arcade::Nibbler::stock_map()
{
    std::ifstream map_file;
	std::string inputString;

	map_file.open("./Games/Nibbler/nibbler_map.txt");
	while(getline(map_file, inputString, '\n'))
		this->_map.push_back(inputString + '\n');
	map_file.close();
}

int Arcade::Nibbler::my_strlenbis(std::string str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            return i;
        i++;
    }
    return 0;
}

void Arcade::Nibbler::delete_last()
{
    int last_bloc_lines = last_tail_positiony();
    int last_bloc_col = last_tail_positionx();

    if (_map[last_bloc_lines][last_bloc_col + 1] == 's') {
        _map[last_bloc_lines][last_bloc_col] = ' ';
        _map[last_bloc_lines][last_bloc_col + 1] = 'd';
        return;
    }
    else if (_map[last_bloc_lines][last_bloc_col - 1] == 's') {
        _map[last_bloc_lines][last_bloc_col] = ' ';
        _map[last_bloc_lines][last_bloc_col - 1] = 'd';
        return;
    }
    else if (_map[last_bloc_lines + 1][last_bloc_col] == 's') {
        _map[last_bloc_lines][last_bloc_col] = ' ';
        _map[last_bloc_lines + 1][last_bloc_col] = 'd';
        return;
    }
    else if (_map[last_bloc_lines - 1][last_bloc_col] == 's'){
        _map[last_bloc_lines][last_bloc_col] = ' ';
        _map[last_bloc_lines - 1][last_bloc_col] = 'd';
        return;
    }
}

int Arcade::Nibbler::last_tail_positiony()
{
    int i = 0;
    int j = 0;
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);

    while (i != lines) {
        while (j != col) {
            if (_map[i][j] == 'd')
                return (i);
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

int Arcade::Nibbler::last_tail_positionx()
{
    int i = 0;
    int j = 0;
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);

    while (i != lines) {
        while (j != col) {
            if (_map[i][j] == 'd')
                return (j);
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

int Arcade::Nibbler::nibbler_positiony()
{
    int i = 0;
    int j = 0;
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);

    while (i != lines) {
        while (j != col) {
            if (_map[i][j] == 'S')
                return (i);
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

int Arcade::Nibbler::nibbler_positionx()
{
    int i = 0;
    int j = 0;
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);

    while (i != lines) {
        while (j != col) {
            if (_map[i][j] == 'S')
                return (j);
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

void Arcade::Nibbler::move_right()
{
    int lines = nibbler_positiony();
    int col = nibbler_positionx();

    if (_map[lines][col + 1] != 'X') {
        _map[lines][col + 1] = 'S';
        _map[lines][col] = 's';
        if ((check_nb_snakegum()) != previous_snake_gum) {
            previous_snake_gum = check_nb_snakegum();
            return;
        }
        else
            delete_last();
    }
}

void Arcade::Nibbler::move_left()
{
    int lines = nibbler_positiony();
    int col = nibbler_positionx();

    if (_map[lines][col - 1] != 'X') {
        _map[lines][col - 1] = 'S';
        _map[lines][col] = 's';
        if ((check_nb_snakegum()) != previous_snake_gum && (check_loose_direction()) != 2) {
            previous_snake_gum = check_nb_snakegum();
            return;
        }
        else
            delete_last();
    }
}

void Arcade::Nibbler::move_up()
{
    int lines = nibbler_positiony();
    int col = nibbler_positionx();

    if (_map[lines - 1][col] != 'X') {
        _map[lines - 1][col] = 'S';
        _map[lines][col] = 's';
        if ((check_nb_snakegum()) != previous_snake_gum) {
            previous_snake_gum = check_nb_snakegum();
            return;
        }
        else
            delete_last();
    }
}

void Arcade::Nibbler::move_down()
{
    int lines = nibbler_positiony();
    int col = nibbler_positionx();

    if (_map[lines + 1][col] != 'X') {
        _map[lines + 1][col] = 'S';
        _map[lines][col] = 's';
        if ((check_nb_snakegum()) != previous_snake_gum) {
            previous_snake_gum = check_nb_snakegum();
            return;
        }
        else
            delete_last();
    }
}

void Arcade::Nibbler::move_nibbler(DIRECTION key)
{
    if (key == UP)
        move_up();
    if (key == DOWN)
        move_down();
    if (key == LEFT && check_nb_snakegum() != 29)
        move_left();
    if (key == RIGHT)
        move_right();
}

int Arcade::Nibbler::check_nb_snakegum()
{
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);
    int stock = 0;

    for (int i = 0; i != lines; ++i) {
        for (int j = 0; j != col; ++j)
            if (_map[i][j] ==  'O')
                stock++;
    }
    return stock;
}

int Arcade::Nibbler::check_nb_tail()
{
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);
    int stock = 0;

    for (int i = 0; i != lines; ++i) {
        for (int j = 0; j != col; ++j)
            if (_map[i][j] ==  's')
                stock++;
    }
    return stock;
}

int Arcade::Nibbler::check_loose_direction()
{
    int lines = nibbler_positiony();
    int col = nibbler_positionx();

    if (_map[lines][col - 1] == 'd')
        return 2;
    else if (_map[lines][col + 1] == 'd')
        return 2;
    else if (_map[lines - 1][col] == 'd')
        return 2;
    else if (_map[lines + 1][col] == 'd')
        return 2;
    if ((check_nb_tail()) < previous_tail_gum) {
        return 2;
    }
    else
        previous_tail_gum = check_nb_tail();
    return 0;
}

extern "C" Arcade::IGames *create()
{
    return (new Arcade::Nibbler());
}