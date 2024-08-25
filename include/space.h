#ifndef _SPACE_H_
#define _SPACE_H_

#include <graphics.h>

class Space {
public:
    int cat;
    PIMAGE* im;
    int getCat();
    int getSelfImg(PIMAGE * SOURCE);
    // int getSelfImg(int x, int y, int h);
    virtual int putSelfImg(int x, int y);
    virtual int react();
    Space();
};

extern Space sp;

#endif