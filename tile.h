#ifndef TILE_H
#define TILE_H

#define TILE_TYPE_UNKNOWN       0
#define TILE_TYPE_BLOCK         1

class Tile
{
    private:
        float x;
        float y;
        float width;
        float height;
        int type;
        unsigned int texture;

    public:
        Tile(void);
        Tile(float x, float y, float width, float height, int type);
        ~Tile(void);
        void render(void);

        float getX(void) { return this->x; };
        float getY(void) { return this->y; };
        float getWidth(void) { return this->width; };
        float getHeight(void) { return this->height; };
};

#endif  // TILE_H
