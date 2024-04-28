/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentinobourgeois
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include "iostream"

Arcade::Pacman::Pacman()
: _time(0), ghost_is_eatable(false), time_to_eat_ghost(15), previous_pac_gum(4)
{
    _temp = openFiles("./Games/Pacman/pacman_map.txt");
    stock_map();
}

Arcade::Pacman::~Pacman()
{
    _map.clear();
}

int Arcade::Pacman::my_get_line(std::string str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '\n')
            j++;
    return j;
}

std::string Arcade::Pacman::openFiles(std::string file)
{
    std::stringstream buffer;
    std::ifstream score_file(file);

    if (score_file.is_open() == false)
        std::cout << "Error openFile: File is not readable" << std::endl;
    else if (score_file.is_open()) {
        buffer << score_file.rdbuf();
    }
    std::string str = buffer.str();
    return str;
}

std::vector<std::string> stock_map_in_temp()
{
    std::ifstream map_file;
	std::string inputString;
    std::vector<std::string> temp;

	map_file.open("./Games/Pacman/pacman_map.txt");
	while(getline(map_file, inputString, '\n'))
		temp.push_back(inputString + '\n');
	map_file.close();
    return temp;
}

void Arcade::Pacman::stock_map()
{
    std::ifstream map_file;
	std::string inputString;

	map_file.open("./Games/Pacman/pacman_map.txt");
	while(getline(map_file, inputString, '\n'))
		this->_map.push_back(inputString + '\n');
	map_file.close();
}

int Arcade::Pacman::my_strlenbis(std::string str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            return i;
        i++;
    }
    return 0;
}

int Arcade::Pacman::pacman_positiony()
{
    int i = 0;
    int j = 0;
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);

    while (i != lines) {
        while (j != col) {
            if (_map[i][j] == 'C')
                return (i);
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

int Arcade::Pacman::pacman_positionx()
{
    int i = 0;
    int j = 0;
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);

    while (i != lines) {
        while (j != col) {
            if (_map[i][j] == 'C')
                return (j);
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

void Arcade::Pacman::move_right()
{
    int lines = pacman_positiony();
    int col = pacman_positionx();

    if (_map[lines][col + 1] != 'X') {
        if ((_map[lines][col + 1] == '1' ||
         _map[lines][col + 1] == '2' ||
          _map[lines][col + 1] == '3' ||
           _map[lines][col + 1] == '4') && ghost_is_eatable == false) {
            _map[lines][col] = ' ';
        }else {
        _map[lines][col + 1] = 'C';
        _map[lines][col] = ' ';
        }
    }
}

void Arcade::Pacman::move_left()
{
    int lines = pacman_positiony();
    int col = pacman_positionx();

    if (_map[lines][col - 1] != 'X') {
       if ((_map[lines][col - 1] == '1' ||
         _map[lines][col - 1] == '2' ||
          _map[lines][col - 1] == '3' ||
           _map[lines][col - 1] == '4') && ghost_is_eatable == false) {
            _map[lines][col] = ' ';
        }else {
        _map[lines][col - 1] = 'C';
        _map[lines][col] = ' ';
        }
    }
}

void Arcade::Pacman::move_up()
{
    int lines = pacman_positiony();
    int col = pacman_positionx();

    if (_map[lines - 1][col] != 'X') {
       if ((_map[lines - 1][col] == '1' ||
         _map[lines - 1][col] == '2' ||
          _map[lines - 1][col] == '3' ||
           _map[lines - 1][col] == '4' )&& ghost_is_eatable == false) {
            _map[lines][col] = ' ';
        }else {
        _map[lines - 1][col] = 'C';
        _map[lines][col] = ' ';
        }
    }
}

void Arcade::Pacman::move_down()
{
    //std::vector<std::string> temp = stock_map_in_temp();
    int lines = pacman_positiony();
    int col = pacman_positionx();

    if (_map[lines + 1][col] != 'X') {
       if ((_map[lines + 1][col] == '1' ||
         _map[lines + 1][col] == '2' ||
          _map[lines + 1][col] == '3' ||
           _map[lines + 1][col] == '4') && ghost_is_eatable == false) {
            _map[lines][col] = ' ';
        }else {
        _map[lines + 1][col] = 'C';
        _map[lines][col] = ' ';
        }
    }
}

int Arcade::Pacman::fghost_positiony(char ghost)
{
     int i = 0;
    int j = 0;
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);

    while (i != lines) {
        while (j != col) {
            if (_map[i][j] ==  ghost)
                return (i);
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

int Arcade::Pacman::fghost_positionx(char ghost)
{
    int i = 0;
    int j = 0;
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);

    while (i != lines) {
        while (j != col) {
            if (_map[i][j] ==  ghost)
                return (j);
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

void Arcade::Pacman::move_ghost_to_capture(char ghost)
{
    int pac_lines = pacman_positiony();
    int pac_col = pacman_positionx();
    int fghost_lines = fghost_positiony(ghost);
    int fghost_col = fghost_positionx(ghost);

      if (fghost_lines == 11 && (fghost_col == 12 || fghost_col == 13 || fghost_col == 14)) {
            if (_time == 10 && _map[fghost_lines - 3][fghost_col] != '1' && _map[fghost_lines - 3][fghost_col] != '2' && _map[fghost_lines - 3][fghost_col] != '3' && _map[fghost_lines - 3][fghost_col] != '4' ) {
        _map[fghost_lines - 3][fghost_col] =  ghost;
        _map[fghost_lines][fghost_col] = ' ';
        _time = 0;
            }
            else _time++;
    }
    else if (pac_lines <= fghost_lines && pac_col <= fghost_col) {
        if (random()%2 == 1) {
    //left dir
            if ( _map[fghost_lines][fghost_col - 1] == 'o' || _map[fghost_lines][fghost_col - 1] == 'C') {
                    _map[fghost_lines][fghost_col - 1] =  ghost;
                    _map[fghost_lines][fghost_col] = 'o';
            }else if (_map[fghost_lines][fghost_col - 1] == ' ') {
                _map[fghost_lines][fghost_col - 1] =  ghost;
                _map[fghost_lines][fghost_col] = ' ';
            }
            else if (_map[fghost_lines][fghost_col - 1] == 'O') {
            _map[fghost_lines][fghost_col - 1] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        } else {
    //up dir
    if (_map[fghost_lines - 1][fghost_col] == 'o' || _map[fghost_lines - 1][fghost_col] == 'C') {
            _map[fghost_lines - 1][fghost_col] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
    } else if (_map[fghost_lines - 1][fghost_col] == ' ') {
         _map[fghost_lines - 1][fghost_col] =  ghost;
            _map[fghost_lines][fghost_col] = ' ';
    }
    else if (_map[fghost_lines - 1][fghost_col] == 'O') {
            _map[fghost_lines - 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
    } else if (pac_lines < fghost_lines && pac_col > fghost_col) {
        if (random()%2 == 1) {
            //down dir
    if (_map[fghost_lines + 1][fghost_col] == 'o' || _map[fghost_lines + 1][fghost_col] == 'C') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'o';
    }
        else if (_map[fghost_lines + 1][fghost_col] == ' ') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines + 1][fghost_col] == 'O') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
        else {
            //left dir
    if (_map[fghost_lines][fghost_col - 1] == 'o' || _map[fghost_lines][fghost_col - 1] == 'C') {
            _map[fghost_lines][fghost_col - 1] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
        }
        else if (_map[fghost_lines][fghost_col - 1] == ' ') {
            _map[fghost_lines][fghost_col - 1] =  ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines][fghost_col - 1] == 'O') {
            _map[fghost_lines][fghost_col - 1] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
    }
    }
    else if (pac_lines > fghost_lines && pac_col < fghost_col) {
        if (random()%2 == 1) {
            //up dir
    if (_map[fghost_lines - 1][fghost_col] == 'o' || _map[fghost_lines - 1][fghost_col] == 'C') {
            _map[fghost_lines - 1][fghost_col] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
    }
        else if (_map[fghost_lines - 1][fghost_col] == ' ') {
            _map[fghost_lines - 1][fghost_col] =  ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines - 1][fghost_col] == 'O') {
            _map[fghost_lines - 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
        else {
            //right dir
    if (_map[fghost_lines][fghost_col + 1] == 'o' || _map[fghost_lines][fghost_col + 1] == 'C') {
            _map[fghost_lines][fghost_col + 1] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
    }
    else if (_map[fghost_lines][fghost_col + 1] == ' ') {
        _map[fghost_lines][fghost_col + 1] =  ghost;
        _map[fghost_lines][fghost_col] = ' ';
    }
    else if (_map[fghost_lines][fghost_col + 1] == 'O') {
            _map[fghost_lines][fghost_col + 1] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
    } else {
        if (random()%2 == 0) {
             //down dir
    if (_map[fghost_lines + 1][fghost_col] == 'o' || _map[fghost_lines + 1][fghost_col] == 'C') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'o';
        }
        else if (_map[fghost_lines + 1][fghost_col] == ' ') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines + 1][fghost_col] == 'O') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
        else {
            //right dir
    if (_map[fghost_lines][fghost_col + 1] == 'o' || _map[fghost_lines][fghost_col + 1] == 'C') {
            _map[fghost_lines][fghost_col + 1] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
    } else if (_map[fghost_lines][fghost_col + 1] == ' ') {
            _map[fghost_lines][fghost_col + 1] =  ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines][fghost_col + 1] == 'O') {
            _map[fghost_lines][fghost_col + 1] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
    }
}

void Arcade::Pacman::move_ghost_to_runaway(char ghost)
{
    int pac_lines = pacman_positiony();
    int pac_col = pacman_positionx();
    int fghost_lines = fghost_positiony(ghost);
    int fghost_col = fghost_positionx(ghost);

    if (pac_lines <= fghost_lines && pac_col <= fghost_col) {
        if (random()%2 == 0) {
             //down dir
    if (_map[fghost_lines + 1][fghost_col] == 'o' || _map[fghost_lines + 1][fghost_col] == 'C') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'o';
        }
        else if (_map[fghost_lines + 1][fghost_col] == ' ') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines + 1][fghost_col] == 'O') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
        else {
            //right dir
    if (_map[fghost_lines][fghost_col + 1] == 'o' || _map[fghost_lines][fghost_col + 1] == 'C') {
            _map[fghost_lines][fghost_col + 1] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
    } else if (_map[fghost_lines][fghost_col + 1] == ' ') {
            _map[fghost_lines][fghost_col + 1] =  ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines][fghost_col + 1] == 'O') {
            _map[fghost_lines][fghost_col + 1] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
    }
    else if (pac_lines < fghost_lines && pac_col > fghost_col) {
        if (random()%2 == 1) {
            //up dir
    if (_map[fghost_lines - 1][fghost_col] == 'o' || _map[fghost_lines - 1][fghost_col] == 'C') {
            _map[fghost_lines - 1][fghost_col] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
    }
        else if (_map[fghost_lines - 1][fghost_col] == ' ') {
            _map[fghost_lines - 1][fghost_col] =  ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines - 1][fghost_col] == 'O') {
            _map[fghost_lines - 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
        else {
            //right dir
    if (_map[fghost_lines][fghost_col + 1] == 'o' || _map[fghost_lines][fghost_col + 1] == 'C') {
            _map[fghost_lines][fghost_col + 1] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
    }
    else if (_map[fghost_lines][fghost_col + 1] == ' ') {
        _map[fghost_lines][fghost_col + 1] =  ghost;
        _map[fghost_lines][fghost_col] = ' ';
    }
    else if (_map[fghost_lines ][fghost_col + 1] == 'O') {
            _map[fghost_lines][fghost_col + 1] = ghost;
            _map[fghost_lines][fghost_col + 1] = 'O';
        }
        }
    }
    else if (pac_lines > fghost_lines && pac_col < fghost_col) {
        if (random()%2 == 1) {
            //down dir
    if (_map[fghost_lines + 1][fghost_col] == 'o' || _map[fghost_lines + 1][fghost_col] == 'C') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'o';
    }
        else if (_map[fghost_lines + 1][fghost_col] == ' ') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines + 1][fghost_col] == 'O') {
            _map[fghost_lines + 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        }
        else {
            //left dir
    if (_map[fghost_lines][fghost_col - 1] == 'o' || _map[fghost_lines][fghost_col - 1] == 'C') {
            _map[fghost_lines][fghost_col - 1] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
        }
        else if (_map[fghost_lines][fghost_col - 1] == ' ') {
            _map[fghost_lines][fghost_col - 1] =  ghost;
            _map[fghost_lines][fghost_col] = ' ';
        }
        else if (_map[fghost_lines][fghost_col - 1] == 'O') {
            _map[fghost_lines][fghost_col - 1] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
    }
    } else {
        if (random()%2 == 1) {
    //left dir
            if ( _map[fghost_lines][fghost_col - 1] == 'o' || _map[fghost_lines][fghost_col - 1] == 'C') {
                    _map[fghost_lines][fghost_col - 1] =  ghost;
                    _map[fghost_lines][fghost_col] = 'o';
            }else if (_map[fghost_lines][fghost_col - 1] == ' ') {
                _map[fghost_lines][fghost_col - 1] =  ghost;
                _map[fghost_lines][fghost_col] = ' ';
            }
            else if (_map[fghost_lines][fghost_col - 1] == 'O') {
            _map[fghost_lines][fghost_col - 1] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
        } else {
    //up dir
    if (_map[fghost_lines - 1][fghost_col] == 'o' || _map[fghost_lines - 1][fghost_col] == 'C') {
            _map[fghost_lines - 1][fghost_col] =  ghost;
            _map[fghost_lines][fghost_col] = 'o';
    } else if (_map[fghost_lines - 1][fghost_col] == ' ') {
         _map[fghost_lines - 1][fghost_col] =  ghost;
            _map[fghost_lines][fghost_col] = ' ';
    }
    else if (_map[fghost_lines - 1][fghost_col] == 'O') {
            _map[fghost_lines - 1][fghost_col] = ghost;
            _map[fghost_lines][fghost_col] = 'O';
        }
    }
    }
}

int Arcade::Pacman::check_nb_pacgum()
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

void Arcade::Pacman::move_ghost()
{
    if ((check_nb_pacgum()) != previous_pac_gum) {
        ghost_is_eatable = true;
        previous_pac_gum = check_nb_pacgum();
    }

    if (ghost_is_eatable == true && time_to_eat_ghost < 15) {
        if (time_to_eat_ghost >= 13)
            ghost_is_eatable = false;
        move_ghost_to_runaway('1');
        move_ghost_to_runaway('2');
        move_ghost_to_runaway('3');
        move_ghost_to_runaway('4');
        time_to_eat_ghost++;
    }
    else {
        move_ghost_to_capture('1');
        move_ghost_to_capture('2');
        move_ghost_to_capture('3');
        move_ghost_to_capture('4');
        time_to_eat_ghost = 0;
    }
}

int Arcade::Pacman::check_is_eat(char ghost)
{
    int col = my_strlenbis(_temp);
    int lines = my_get_line(_temp);

    for (int i = 0; i != lines; ++i) {
        for (int j = 0; j != col; ++j)
            if (_map[i][j] == ghost)
                return 1;
    }
    return 0;
}

int Arcade::Pacman::respawn_ghost()
{
    if ((check_is_eat('1')) == 0)
                        _map[8][12] = '1';
                if ((check_is_eat('2')) == 0)
                        _map[8][13] = '2';
                if ((check_is_eat('3')) == 0)
                        _map[8][14] = '3';
                if ((check_is_eat('4')) == 0)
                        _map[8][15] = '4';
    return 0;
}

void Arcade::Pacman::move_pacman(DIRECTION key)
{
    if (key == UP)
        move_up();
    if (key == DOWN)
        move_down();
    if (key == LEFT)
        move_left();
    if (key == RIGHT)
        move_right();
}

void Arcade::Pacman::respawn_pacman()
{
    int pac_lines = pacman_positiony();
    int pac_col = pacman_positionx();

    if (pac_lines == 11 && pac_col == 27){
        _map[11][1] = 'C';
        _map[11][27] = ' ';
    }
    else if (pac_lines == 11 && pac_col == 1) {
        _map[11][26] = 'C';
        _map[11][1] = ' ';
    }
    else return;
}

extern "C" Arcade::IGames *create()
{
    return (new Arcade::Pacman());
}