#ifndef GAME_H
#define GAME_H

class Game
{
    private:
        float width;
        float height;
        std::string caption;
        bool isRunning;
        int fps;
        SDL_Event event;
        Player *player;
        std::vector<Tile *> tile;
        Mix_Music *music;

        void events(SDL_Event event);
        void init(void);
        void splash(void);
        void loadMap(void);
        void render(void);
        void logic(void);

    public:
        Game(void);
        ~Game(void);
        void mainLoop(void);
};

#endif  // GAME_H
