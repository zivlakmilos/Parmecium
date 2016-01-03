#include "main.h"
#include "functions.h"

unsigned int loadModel(SDL_Surface *image, SDL_Rect imageRect)
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

    SDL_BlitSurface(image, &imageRect, tmpImage, &tmpRect); // copy image

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
