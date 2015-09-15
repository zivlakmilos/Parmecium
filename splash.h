#ifndef SPLASH_H
#define SPLASH_H

class Splash
{
    private:
        float x;
        float y;
        float width;
        float height;
        float wWidth;
        float wHeight;
        int time;
        Mix_Music *music;
        unsigned int texture;
        void loadTexture(void);
        unsigned int loadModel(SDL_Surface *image, SDL_Rect imageRect);

    public:
        Splash(float wWidth, float wHeight);
        ~Splash(void);
        void show(void);
};

#endif  // SPLASH_H
