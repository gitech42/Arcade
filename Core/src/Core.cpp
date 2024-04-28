/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-quentin.bourgeois
** File description:
** Core
*/

#include "Core.hpp"
#include "IGraphicals.hpp"
#include "IGames.hpp"
#include "LibHandler.hpp"

Arcade::Core::Core()
: _graphicalsLib(0), _gamesLib(0), _lastDirection(Arcade::Right)
{
}

Arcade::Core::~Core()
{
}

int getPrevious(int index, int size) {
    if (index - 1 < 0)
        return size - 1;
    return index - 1;
}

int getForward(int index, int size) {
    if (index + 1 >= size)
        return 0;
    return index + 1;
}

Arcade::Key Arcade::Core::handleGameKey(Key c, Arcade::IGames **currentGame, Arcade::IGraphicals **graph, std::vector<Element_t> &graphicals, std::vector<Element_t> &games)
{
    createGraphicals *graphicals_funcs = NULL;
    createGames *games_funcs = NULL;

    if (c == Arcade::M) {
        delete *currentGame;
        *currentGame = nullptr;
        _libGameHandler.closeLib();
        return c;
    }
    if (c == Arcade::F3) {
        for (int i = 0; (long unsigned int) i != _gamesLib.size(); ++i) {
           if (games[i].selected == true) {
               games[i].selected = false;
               games[getPrevious(i, _gamesLib.size())].selected = true;
               _libGameHandler.closeLib();
               _libGameHandler.openLib("./lib/" + games[getPrevious(i, _gamesLib.size())].name);
               games_funcs = (createGames*)_libGameHandler.getFunctionFromLib("create");
               *currentGame = games_funcs();
               return c;
           }
        }
    }
    if (c == Arcade::F4) {
        for (int i = 0; (long unsigned int) i != _gamesLib.size(); ++i) {
            if (games[i].selected == true) {
                games[i].selected = false;
                games[getForward(i, _gamesLib.size())].selected = true;
                _libGameHandler.closeLib();
                _libGameHandler.openLib("./lib/" + games[getForward(i, _gamesLib.size())].name);
                games_funcs = (createGames*)_libGameHandler.getFunctionFromLib("create");
                *currentGame = games_funcs();
                return c;
            }
        }
    }
    if (c == Arcade::F1) {
        for (int i = 0; (long unsigned int) i != _graphicalsLib.size(); ++i) {
            if (graphicals[i].selected == true) {
                graphicals[i].selected = false;
                graphicals[getPrevious(i, _graphicalsLib.size())].selected = true;
                (*graph)->destroy();
                _libGraphicHandler.closeLib();
                _libGraphicHandler.openLib("./lib/" + graphicals[getPrevious(i, _graphicalsLib.size())].name);
                graphicals_funcs = (createGraphicals*)_libGraphicHandler.getFunctionFromLib("create");
                *graph = graphicals_funcs();
                return c;
            }
        }
    }
    if (c == Arcade::F2) {
        for (int i = 0; (long unsigned int) i != _graphicalsLib.size(); ++i) {
            if (graphicals[i].selected == true) {
                graphicals[i].selected = false;
                graphicals[getForward(i, _graphicalsLib.size())].selected = true;
                (*graph)->destroy();
                _libGraphicHandler.closeLib();
                _libGraphicHandler.openLib("./lib/" + graphicals[getForward(i, _graphicalsLib.size())].name);
                graphicals_funcs = (createGraphicals*)_libGraphicHandler.getFunctionFromLib("create");
                *graph = graphicals_funcs();
                return c;
            }
        }
    }
    if (c == Arcade::Up || c == Arcade::Z
        || c == Arcade::Down || c == Arcade::S
        || c == Arcade::Left || c == Arcade::Q
        || c == Arcade::D || c == Arcade::Right) {
            _lastDirection = c;
            return c;
        }
    return c;
}

Arcade::IGames *Arcade::Core::handleMenuKey(Key c, std::vector<Element_t> &gameMenu, std::vector<Element_t> &graphicals, IGraphicals **graph)
{
    createGames *games_funcs = NULL;
    createGraphicals *graphicals_funcs = NULL;
    IGames *games;

    if (c == Arcade::Enter) {
        for (long unsigned int i = 0; i != _gamesLib.size(); ++i)
            if (gameMenu[i].selected == 1) {
                _libGameHandler.openLib("./lib/" + gameMenu[i].name);
                games_funcs = (createGames*)_libGameHandler.getFunctionFromLib("create");
                games = games_funcs();
                return games;
            }
    } if (c == Arcade::Down) {
        for (long unsigned int i = 0; i != _gamesLib.size(); i++)
            if (gameMenu[i].selected == true) {
                gameMenu[i].selected = false;
                gameMenu[getForward(i, _gamesLib.size())].selected = true;
                return nullptr;
            }
    } if (c == Arcade::Up) {
        for (int i = 0; (long unsigned int)i != _gamesLib.size(); i++)
            if (gameMenu[i].selected == true) {
                gameMenu[i].selected = false;
                gameMenu[getPrevious(i, _gamesLib.size())].selected = true;
                return nullptr;
            }
    } if (c == Arcade::F1) {
        for (int i = 0; (long unsigned int) i != _graphicalsLib.size(); ++i) {
            if (graphicals[i].selected == true) {
                graphicals[i].selected = false;
                graphicals[getPrevious(i, _graphicalsLib.size())].selected = true;
                (*graph)->destroy();
                _libGraphicHandler.closeLib();
                _libGraphicHandler.openLib("./lib/" + graphicals[getPrevious(i, _graphicalsLib.size())].name);
                graphicals_funcs = (createGraphicals*)_libGraphicHandler.getFunctionFromLib("create");
                *graph = graphicals_funcs();
                return nullptr;
            }
        }
    } if (c == Arcade::F2) {
        for (int i = 0; (long unsigned int) i != _graphicalsLib.size(); ++i) {
            if (graphicals[i].selected == true) {
                graphicals[i].selected = false;
                graphicals[getForward(i, _graphicalsLib.size())].selected = true;
                (*graph)->destroy();
                _libGraphicHandler.closeLib();
                _libGraphicHandler.openLib("./lib/" + graphicals[getForward(i, _graphicalsLib.size())].name);
                graphicals_funcs = (createGraphicals*)_libGraphicHandler.getFunctionFromLib("create");
                *graph = graphicals_funcs();
                return nullptr;
            }
        }
    }
    return nullptr;
}

std::vector<Arcade::Element_t> initCoreElement(std::vector<std::string> map, std::vector<Arcade::Element_t> tmp)
{
    int nb = 0;
    int index = 0;
    std::string assets = "./assets/";
    std::string tmp2 = "";
    Arcade::Element_t insert;

    for (size_t i = 0; i != map.size(); ++i)
        for (int j = 0; map[i][j]; ++j)
            nb++;
    
    if (tmp.empty() == false)
        tmp.clear();
    for (size_t i = 0; i != map.size(); ++i) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == ' ' || map[i][j] == '\n')
                continue;
            insert.name = map[i][j];
            insert.pos_x = j;
            insert.pos_y = i;
            tmp2 = assets + map[i][j];
            insert.texturePath = tmp2;
            insert.texturePath = insert.texturePath + ".png";
            insert.printable = true;
            insert.isPrint = false;
            insert.size = nb;
            tmp.push_back(insert);
            index++;
        }
    }
    return tmp;
}

void Arcade::Core::launchCore(const std::string &startingLib)
{
    Arcade::IGraphicals *graphics = NULL;
    Arcade::IGames *games = NULL;
    createGraphicals *graphic_funcs = NULL;
    std::vector<Element_t> CoreGame;
    std::vector<Element_t> menu;
    std::vector<Element_t> gameMenu;
    std::vector<Element_t> scoreDisp;
    Element_t insert;
    Key tmp = D;

    if (!(_libGraphicHandler.openLib(startingLib)))
        return;
    graphic_funcs = (createGraphicals*)_libGraphicHandler.getFunctionFromLib("create");
    graphics = graphic_funcs();
    if (!graphics) {
        std::cout << "Failed to load graphics" << std::endl;
        return;
    }

    getScore();
    getGamesLib();
    getGraphicalsLib();

    for (auto& x:_score) {
        insert.name = x.first;
        insert.value = x.second;
        insert.printable = true;
        insert.isPrint = false;
        scoreDisp.push_back(insert);
    }
    for (long unsigned int i = 0; i != _graphicalsLib.size(); ++i) {
        if (startingLib.substr(startingLib.find_last_of("/\\") + 1) == _graphicalsLib[i])
            insert.selected = true;
        else
            insert.selected = false;
        insert.name = _graphicalsLib[i];
        insert.printable = true;
        insert.isPrint = false;
        menu.push_back(insert);
    }
    for (long unsigned int i = 0; i != _gamesLib.size(); i++) {
        if (i == 0)
            insert.selected = true;
        else
            insert.selected = false;
        insert.name = _gamesLib[i];
        insert.printable = true;
        gameMenu.push_back(insert);
    }
    while ((tmp = graphics->listenEvent()) != Arcade::End) {
        if (!games) {
            games = handleMenuKey(tmp, gameMenu, menu, &graphics);
            graphics->display_menu(menu, gameMenu);
            graphics->display_score(scoreDisp);
            graphics->refresh_w();
        } else {
            tmp = handleGameKey(tmp, &games, &graphics, menu, gameMenu);
            if (games) {
                if (tmp < 1 || tmp > 8) {
                    games->start(static_cast<Arcade::DIRECTION>(_lastDirection));
                } else
                    games->start(static_cast<Arcade::DIRECTION>(tmp));
                CoreGame = initCoreElement(games->getMap(), CoreGame);
                if (games->checkEnd() == 1 || games->checkEnd() == 2) {
                    delete games;
                    games = nullptr;
                }
                graphics->display_game(CoreGame);
                graphics->display_score(scoreDisp);
                graphics->refresh_w();
            }
        }
    }
    if (graphics)
        graphics->destroy();

    writeFinalScore();
    _libGraphicHandler.closeLib();
}

void Arcade::Core::displayMenu()
{
}

std::string openFiles(std::string file)
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

void Arcade::Core::getScore()
{
    std::string buffer = openFiles("./Core/Score.txt");
    std::string temp;
    std::string name;
    std::string score;
    int i = 0;

    while (buffer[i] != '\0') {
        while (buffer[i] != ':' && buffer[i] >= 'A' && buffer[i] <= 'z') {
            name += buffer[i];
            i++;
        }
        i++;
        while (buffer[i] != '\n' && buffer[i] >= '0' && buffer[i] <= '9') {
            score += buffer[i];
            i++;
        }
        _score.insert(make_pair(name, atoi(score.c_str())));
        name.clear();
        score.clear();
        i++;
    }
}

void Arcade::Core::getGraphicalsLib()
{
    DIR *dir = opendir("./lib");
    struct dirent *sd;
    std::string array[13] = {"arcade_ndk++.so",
                            "arcade_aalib.so",
                            "arcade_libcaca.so",
                            "arcade_allegro5.so",
                            "arcade_xlib.so",
                            "arcade_gtk+.so",
                            "arcade_sfml.so",
                            "arcade_irrlicht.so",
                            "arcade_opengl.so",
                            "arcade_vulkan.so",
                            "arcade_ncurses.so",
                            "arcade_sdl2.so",
                            "arcade_qt5.so"};

    if (dir == NULL)
        return;
    while ((sd = readdir(dir))) {
        if (sd->d_name[0] != '.') {
           for (int i = 0; i != 13; ++i)
                if ((array[i].compare(std::string(sd->d_name))) == 0)
                    _graphicalsLib.push_back(array[i]);
        }
    }
}

void Arcade::Core::getGamesLib()
{
    DIR *dir = opendir("./lib");
    struct dirent *sd;
    std::string array[5] = {"arcade_nibbler.so",
                            "arcade_qix.so",
                            "arcade_pacman.so",
                            "arcade_centipede.so",
                            "arcade_solarfox.so" };
    if (dir == NULL)
        return;
    while ((sd = readdir(dir))!= NULL) {
        if (sd->d_name[0] != '.')
            for (int i = 0; i != 5; ++i)
                if ((array[i].compare(std::string(sd->d_name))) == 0)
                    _gamesLib.push_back(array[i]);
    }
}

void Arcade::Core::addUserInScore(std::string &name)
{
    std::ofstream file;
    file.open("./Core/Score.txt", std::ios::out|std::ios::app);
    file << '\n' + name + ":0";
    file.close();
    _score.insert(make_pair(name, 0));
}

void Arcade::Core::writeFinalScore()
{
    std::ofstream file;
    file.open("./Core/Score.txt");
    for (auto x : _score)
    file << x.first << ":" << x.second << "\n";
    file.close();
}