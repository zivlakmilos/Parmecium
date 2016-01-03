#include "main.h"
#include "tile.h"

Tile::Tile(void)
{
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
    this->type = TILE_TYPE_UNKNOWN;
}

Tile::Tile(float x, float y, float width, float height, int type)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->type = type;
}

Tile::~Tile(void)
{
}

void Tile::render(void)
{
    glColor4ub(0, 0, 255, 255); // Blue color
    glBegin(GL_QUADS);
        glVertex2f(this->x, this->y);
        glVertex2f(this->x + this->width, this->y);
        glVertex2f(this->x + this->width, this->y + this->height);
        glVertex2f(this->x, this->y + this->height);
    glEnd();
}
