#pragma once
#ifndef WIDGETCONTAINER_H
#define WIDGETCONTAINER_H

#include <unordered_map> 
#include <exception>
#include <iostream>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "Widget.h"
#include "EventHandler.h"

using namespace std;

class WidgetContainer : public Widget, public boost::enable_shared_from_this<WidgetContainer>
{
private:
    unordered_map<string, sharedPtrWidget> widgets;
    vector<sharedPtrWidget> vWidgets;
    SDL_Renderer *renderer;
public: 
    WidgetContainer(SDL_Renderer *);
    virtual ~WidgetContainer(void); 
    void add(sharedPtrWidget);
    void update(float dt);
    weakPtrWidget getWidget(string);
    void processEvent(SDL_Event);
    void render();
};

#endif
