# Arcade
## Compilation et execution
- À la racine du dossier, compilez le projet grâce à la commande "make"
- Executez le binaire ainsi crée avec la librairie graphique de votre choix situé dans le dossier lib "./arcade lib/arcade_[Librarie graphique].so"
- Lors du run-time, vous pouvez changer la librarie graphique (F1 ou F2 (P ou U en ncurse)) ou le jeu en cours (F3 ou F4 (U ou I en ncurse))

# Documentation
## Classe Core
La classe Core est appelé dans le main, elle permet de manipuler les libraries, ainsi qu'a les faire communiquer entre elle, par le biais d'une structure Element_t

>> Core.hpp
```c++
namespace Arcade {
    class Core {
        public:
            Core();
            ~Core();
            // Get les information importantes
            void getScore();
            void getGraphicalsLib();
            void getGamesLib();
            // Gestion du score
            void addUserInScore(std::string &name);
            void writeFinalScore();
            // Fonction appelé dans le main qui permet de lancer le programme
            void launchCore(const std::string &startingLib);
            // Display le menu
            void displayMenu();
            // recupère les info et execute des actions en fonction des inputs
            Arcade::IGames *handleMenuKey(Key c, std::vector<Element_t> &gameMenu, std::vector<Element_t> &graphicals, IGraphicals *(*graph));
            Arcade::Key handleGameKey(Key c, Arcade::IGames **currentGame, Arcade::IGraphicals **graph, std::vector<Element_t> &graphicals, std::vector<Element_t> &games);
        protected:
        private:
            Arcade::LibHandler _libGameHandler;
            Arcade::LibHandler _libGraphicHandler;
            std::vector<std::string> _graphicalsLib;
            std::vector <std::string> _gamesLib;
            std::map<std::string, int> _score;
            Key _lastDirection;
    };
}
```

## Classe LibHandler
La classe LibHandler permet de stocker le contenu de la librarie .so et de gèrer son ouverture ainsi que sa fermeture
>> LibHandler.hpp
```c++
namespace Arcade {
    class LibHandler {
        public:
            LibHandler();
            ~LibHandler();
            bool openLib(const std::string &filename);
            // Recupère une fonction présent dans le .so
            void *getFunctionFromLib(const std::string &func);
            void closeLib();
        protected:
            void *_buffer;
            void *_addr;
        private:
    };
}
```

## Interfaces
-L'interface IGames permet de manipuler n'importe quel jeu grâce aux fonctions contenu dans l'interface. Si vous voulez ajouter un jeu, il suffit de faire une classe qui hérite de l'interface IGames, en prenant soin de bien recoder les fonctions en virtual nécessaire pour lancer le jeu. Ajoutez la compilation de votre jeu dans le Makefile présent dans le dossier ./Games/
>> IGames.hpp
```c++
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
            // Restart le jeu
            virtual void restart() = 0;
            // Start le jeu
            virtual void start(DIRECTION key) = 0;
            // Faire bouger en fonction d'une direction
            virtual void move(DIRECTION) = 0;
            // Check la condition de sortie
            virtual int checkEnd() = 0;
            // Return la map
            virtual std::vector<std::string> getMap() = 0;
        protected:
        private:
    };
}
```
-L'interface IGraphicals nous permettent de manipuler les libraries graphiques.
Si vous souhaitez ajouter une librarie graphique, les étapes sont similaires que pour les jeux.
>> IGraphicals.hpp
```c++
namespace Arcade {
    class IGraphicals {
        public:
           virtual ~IGraphicals() = default;
           // Refresh la window
           virtual void refresh_w() = 0;
           // Display le jeu
           virtual void display_game(std::vector<Element_t> CoreGame) = 0;
           // Display le menu
           virtual void display_menu(std::vector<Element_t> menu, std::vector<Element_t> gameMenu) = 0;
           // Display le score
           virtual void display_score(std::vector<Element_t> score) = 0;
           // Return une touche absolu compatible pour le Core
           virtual Key listenEvent() = 0;
           // Destroy la window
           virtual void destroy() = 0;

        protected:
        private:
    };
}
```

-Il est important d'ajouter un entryPoint nous permettant de récupérer un pointeur sur la classe présent dans le shared object ouvert
Exemple avec le jeu Pacman:
>> Pacman.cpp
```c++
extern "C" Arcade::IGames *create()
{
    return (new Arcade::Pacman());
}
```

Exemple avec la librarie Sfml:
>>Sfml.cpp
```c++
extern "C" Arcade::IGraphicals *create()
{
    return (new Arcade::Sfml());
}
```

## Enum key
L'enum Key présente dans l'interface IGraphicals nous permet d'envoyer au Core une touche absolu qui ne diffère pas selon la librarie graphique
>> IGraphicals.hpp
```c++
    enum Key {
        F9,
        Up,
        Down,
        Left,
        Right,
        P,
        U,
        O,
        Nothing,
        Space,
        Enter,
        F1,
        F2,
        F3,
        F4,
        F5,
        M,
        End
    };
```

## Structure Element_t 
La structure Element_t nous permet de communiquer entre le Core et les libraries, c'est cette structure qui est manipulé par les libraries graphiques pour savoir ce qu'elles ont a affiché.
>> IGraphicals.hpp
```c++
    typedef struct Element_s {
        // Nom de cet element 
        std::string name;
        // Path de la texture si elle en a une
        std::string texturePath;
        // Position
        float pos_x;
        float pos_y;
        // Important boolean
        bool printable;
        bool isPrint;
        bool selected;
        // Value si besoin (exemple le score)
        int value;

    } Element_t;
```