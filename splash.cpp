#include "main.h"
#include "splash.h"

Splash::Splash(float wWidth, float wHeight)
{
    this->width = 300;
    this->height = 300;
    this->wWidth = wWidth;
    this->wHeight = wHeight;
    this->x = wWidth / 2 - this->width / 2;
    this->y = wHeight / 2 - this->height / 2;
    this->time = 4000;
    this->music = NULL;
    loadTexture();
}

Splash::~Splash(void)
{
}

void Splash::loadTexture(void)
{
    SDL_Surface *image = IMG_Load("data/foka logo.png");
    SDL_DisplayFormatAlpha(image);
    SDL_Rect imageRect;

    imageRect.x = 0;
    imageRect.y = 0;
    imageRect.w = 700;
    imageRect.h = 700;
    this->texture = this->loadModel(image, imageRect);

    SDL_FreeSurface(image);
}

unsigned int Splash::loadModel(SDL_Surface *image, SDL_Rect imageRect)
{
    SDL_Surface *tmpImage;  // Tempoary surface
    tmpImage = SDL_CreateRGBSurface(0, imageRect.w, imageRect.h,
            image->format->BitsPerPixel, image->format->Rmask,
            image->format->Gmask, image->format->Bmask, image->format->Amask);
    SDL_SetAlpha(image, 0, 0);

    SDL_Rect tmpRect;   // Tempoary rectangle for dest information
    tmpRect.x = 0;
    tmpRect.y = 0;
    tmpRect.w = imageRect.w;
    tmpRect.h = imageRect.h;

    SDL_BlitSurface(image, &imageRect, tmpImage, &tmpRect);

    unsigned object(0);
    glGenTextures(1, &object);
    glBindTexture(GL_TEXTURE_2D, object);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tmpImage->w, tmpImage->h, 0,
            GL_RGBA, GL_UNSIGNED_BYTE, tmpImage->pixels);

    SDL_FreeSurface(tmpImage);

    return object;
}

void Splash::show(void)
{
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    music = Mix_LoadMUS("data/muzika/music.wav");
    Mix_PlayMusic(music, -1);

    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glOrtho(0, this->wWidth, 0, this->wHeight, -1, 1);

    // Begin render

    glColor4ub(255, 255, 255, 255); // White color
    glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(this->wWidth, 0);
        glVertex2f(this->wWidth, this->wHeight);
        glVertex2f(0, wHeight);
    glEnd();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->texture);
    glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex2f(this->x, this->y);
        glTexCoord2d(1, 1); glVertex2f(this->x + this->width, this->y);
        glTexCoord2d(1, 0); glVertex2f(this->x + this->width, this->y + this->height);
        glTexCoord2d(0, 0); glVertex2f(this->x, this->y + this->height);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    // End render

    glPopMatrix();
    SDL_GL_SwapBuffers();
    SDL_Delay(time);
    Mix_FreeMusic(music);
}
