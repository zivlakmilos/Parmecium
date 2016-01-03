#ifndef PLAYER_H
#define PLAYER_H

// Player move type definition
#define PLAYER_MOVE_ADD     0
#define PLAYER_MOVE_DELETE  1

// Player move state definition
#define PLAYER_MOVE_DOWN    2
#define PLAYER_MOVE_RIGHT   3
#define PLAYER_MOVE_UP      4
#define PLAYER_MOVE_LEFT    5

// Player angle
#define PLAYER_ANGLE_DOWN   6
#define PLAYER_ANGLE_RIGHT  7
#define PLAYER_ANGLE_UP     8
#define PLAYER_ANGLE_LEFT   9

typedef struct sPlayerMove
{
    bool down;
    bool right;
    bool up;
    bool left;
} PlayerMove;

typedef struct sPlayerTexture
{
    unsigned int down;
    unsigned int right;
    unsigned int up;
    unsigned int left;
} PlayerTexture;

class Player
{
    private:
        float x;
        float y;
        float width;
        float height;
        float speed;
        float helth;
        int angle;
        PlayerMove moveState;
        PlayerTexture texture;

    public:
        Player(void);
        ~Player(void);
        void move(void);
        void changeMoveState(int type, int size);
        void loadTexture(void);
        void render(void);
        void collision(float width, float height);
        void collision(Tile *tile);
        /*
        float getX(void);
        float getY(void);
        float getWidth(void);
        float getHeight(void);
        void setX(float value);
        void setY(float value);
        */
};

#endif  // PLAYER_H
