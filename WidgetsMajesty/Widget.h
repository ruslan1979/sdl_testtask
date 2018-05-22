#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <SDL.h>
#include <stdio.h>
#include <iostream>

class EventHandler;
class WidgetContainer;

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include "EventHandler.h"

using namespace std;

typedef boost::shared_ptr<EventHandler> ptrSharedEventHandler;
typedef boost::shared_ptr<WidgetContainer> ptrSharedWidgetContainer;

class Widget
{
private:
    string id;
    int order;
    float posX;
    float posY;
    float width;
    float height;
    bool visible;
    SDL_Renderer *renderer;

    boost::weak_ptr<WidgetContainer> ptrWidgetContnr;

    vector<ptrSharedEventHandler> ptrHandlers;
    bool isCursorInside(int, int);
public:
    Widget(SDL_Renderer *renderer);
    void initWidget();
    
    void setId(const string&); // установить строковый идентификатор
    string getId();

    void setOrder(int); // для изменения порядка отрисовки виджетов на экране (аппаратный z-order не используется)
    int getOrder();

    virtual void onPressLMouseButton(void); // нажатие левой кнопки мыши
    virtual void onReleaseLMouseButton(void); // отпускание левой кнопки мыши
    virtual void onEnterLMouseButton(void); // попадание мыши в виджет
    virtual void onLeaveLMouseButton(void); // выход мыши за пределы виджета

    bool isVisible();

    void setContainer(ptrSharedWidgetContainer);
    boost::weak_ptr<WidgetContainer> getContainer();

    void setPos(float x, float y); // положение виджета
    float getPosX();
    float getPosY();
    float getWidth();
    float getHeight();

    void setSize(float w, float h); // размер виджета. Предполагается что все виджеты – прямоугольники
    
    bool update(float); // обновление состояния виджета
    
    virtual void render(); // отрисовка виджета 

    void show(); // показать виджет
    void hide(); // скрыть виджет

    void processEvent(SDL_Event e);
    void addEventHandler(ptrSharedEventHandler); // регистрация фунций обратного вызова для различных союбытий виджета. Параметры требуется продумать самостоятельно
    virtual ~Widget() {};

};

#endif