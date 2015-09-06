#ifndef BARRIER_H
#define BARRIER_H

class Barrier
{
    private:
        float x;
        float y;
        float width;
        float height;
        unsigned int texture;

    public:
        Barrier(void);
        ~Barrier(void);
        void collision(Player *player);
}

#endif  // BARRIER_H
