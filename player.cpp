#include "main.h"
#include "functions.h"
#include "tile.h"
#include "player.h"

Player::Player(void)
{
    this->x = 0.0;
    this->y = 0.0;
    this->width = 74.0;
    this->height = 90.0;
    this->speed = 5.0;
    this->helth = 3.0;
    this->moveState.down = false;
    this->moveState.right = false;
    this->moveState.up = false;
    this->moveState.left = false;
    this->angle = PLAYER_ANGLE_DOWN;
}

Player::~Player(void)
{
}

void Player::move(void)
{
    if(this->moveState.down)
    {
        this->y -= this->speed;
        this->angle = PLAYER_ANGLE_DOWN;
    }
    else if(this->moveState.up)
    {
        this->y += this->speed;
        this->angle = PLAYER_ANGLE_UP;
    }
    else if(this->moveState.left)
    {
        this->x -= this->speed;
        this->angle = PLAYER_ANGLE_LEFT;
    }
    else if(this->moveState.right)
    {
        this->x += this->speed;
        this->angle = PLAYER_ANGLE_RIGHT;
    }
}

void Player::changeMoveState(int type, int state)
{
    switch(type)
    {
        case PLAYER_MOVE_ADD:
            switch(state)
            {
                case PLAYER_MOVE_DOWN:
                    this->moveState.down = true;
                    break;
                case PLAYER_MOVE_RIGHT:
                    this->moveState.right = true;
                    break;
                case PLAYER_MOVE_UP:
                    this->moveState.up = true;
                    break;
                case PLAYER_MOVE_LEFT:
                    this->moveState.left = true;
                    break;
            }
            break;
        case PLAYER_MOVE_DELETE:
            switch(state)
            {
                case PLAYER_MOVE_DOWN:
                    this->moveState.down = false;
                    break;
                case PLAYER_MOVE_RIGHT:
                    this->moveState.right = false;
                    break;
                case PLAYER_MOVE_UP:
                    this->moveState.up = false;
                    break;
                case PLAYER_MOVE_LEFT:
                    this->moveState.left = false;
                    break;
            }
            break;
    }
}

void Player::loadTexture(void)
{
    SDL_Surface *image = IMG_Load("data/player.png");
    //SDL_Surface *image = IMG_Load("data/foka2.png");
    SDL_DisplayFormatAlpha(image);
    SDL_Rect imageRect;

    /*
    imageRect.x = 0;
    imageRect.y = 0;
    imageRect.w = 200.0;
    imageRect.h = 159.0;
    this->texture.right = this->loadModel(image, imageRect);
    imageRect.x += imageRect.w;
    this->texture.left = this->loadModel(image, imageRect);
    imageRect.x += imageRect.w;
    imageRect.w = 135.0;
    this->texture.down = this->loadModel(image, imageRect);
    imageRect.x += imageRect.w;
    this->texture.up = this->loadModel(image, imageRect);
    */

    /*
    imageRect.x = 0;
    imageRect.y = 0;
    imageRect.w = 300;
    imageRect.h = 300;
    this->texture.down = this->loadModel(image, imageRect);
    */

    imageRect.x = 0;
    imageRect.y = 0;
    imageRect.w = 300;
    imageRect.h = 300;

    image = IMG_Load("data/foka.png");
    this->texture.down = loadModel(image, imageRect);
    image = IMG_Load("data/foka2.png");
    this->texture.right = loadModel(image, imageRect);
    image = IMG_Load("data/foka3.png");
    this->texture.left = loadModel(image, imageRect);
    image = IMG_Load("data/foka4.png");
    this->texture.up = loadModel(image, imageRect);

    SDL_FreeSurface(image);
}

// Render player
void Player::render(void)
{
    glColor4ub(255, 255, 255, 255); // White color
    glEnable(GL_TEXTURE_2D);

    switch(this->angle)
    {
        case PLAYER_ANGLE_DOWN:
            glBindTexture(GL_TEXTURE_2D, this->texture.down);
            break;
        case PLAYER_ANGLE_RIGHT:
            glBindTexture(GL_TEXTURE_2D, this->texture.right);
            break;
        case PLAYER_ANGLE_UP:
            glBindTexture(GL_TEXTURE_2D, this->texture.up);
            break;
        case PLAYER_ANGLE_LEFT:
            glBindTexture(GL_TEXTURE_2D, this->texture.left);
            break;
    }

    glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex2f(this->x, this->y);
        glTexCoord2d(1, 1); glVertex2f(this->x + this->width, this->y);
        glTexCoord2d(1, 0); glVertex2f(this->x + this->width, this->y + this->height);
        glTexCoord2d(0, 0); glVertex2f(this->x, this->y + this->height);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void Player::collision(float width, float height)
{
    if(this->x < 0)
        this->x = 0;
    else if(this->x + this->width > width)
        this->x = width - this->width;
    if(this->y < 0)
        this->y = 0;
    else if(this->y + this->height > height)
        this->y = height - this->height;
}

void Player::collision(Tile *tile)
{
    if(this->x + this->width > tile->getX() &&
            this->x < tile->getX() + tile->getWidth())
        if(this->y + this->height > tile->getY() &&
                this->y < tile->getY() + tile->getHeight())
        {
            /*
            if(this->moveState.down)
                this->y = tile->getY() + tile->getHeight();
            else if(this->moveState.right)
                this->x = tile->getX() - this->width;
            else if(this->moveState.up)
                this->y = tile->getY() - this->height;
            else if(this->moveState.left)
                this->x = tile->getX() + tile->getWidth();
            */
            switch(this->angle)
            {
                case PLAYER_ANGLE_DOWN:
                    this->y = tile->getY() + tile->getHeight();
                    break;
                case PLAYER_ANGLE_RIGHT:
                    this->x = tile->getX() - this->width;
                    break;
                case PLAYER_ANGLE_UP:
                    this->y = tile->getY() - this->height;
                    break;
                case PLAYER_ANGLE_LEFT:
                    this->x = tile->getX() + tile->getWidth();
                    break;
            }
        }
}
