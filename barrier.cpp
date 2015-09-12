#include "main.h"
#include "player.h"
#include "barrier.h"

Barrier::Barrier(void)
{
    this->x = 100,0f;
    this->y = 100.0f;
    this->width = 100.0f;
    this->height = 100.0f;
}

Barrier::~Barrier(void)
{
}

void Barrier::collision(Player *player)
{
    if(player->getX() + player->getWidth() > this->x &&
            player->getY() + player->getHeight() > this->y)
    {
    }
    else if(player->getX() < this->x + this->width &&
        player->getY() < this->y + this->height)
    {
    }
}
