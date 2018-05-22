#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>

#include "Widget.h"

using namespace std;

class Image :
    public Widget
{
private :
    SDL_Texture *imageTex;
    SDL_Renderer *renderer;
public:
    Image(const string imageFilePath, SDL_Renderer *renderer);  
    virtual void render();
    void doRender();
    ~Image();
};

#endif