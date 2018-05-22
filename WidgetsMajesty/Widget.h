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
    
    void setId(const string&); // ���������� ��������� �������������
    string getId();

    void setOrder(int); // ��� ��������� ������� ��������� �������� �� ������ (���������� z-order �� ������������)
    int getOrder();

    virtual void onPressLMouseButton(void); // ������� ����� ������ ����
    virtual void onReleaseLMouseButton(void); // ���������� ����� ������ ����
    virtual void onEnterLMouseButton(void); // ��������� ���� � ������
    virtual void onLeaveLMouseButton(void); // ����� ���� �� ������� �������

    bool isVisible();

    void setContainer(ptrSharedWidgetContainer);
    boost::weak_ptr<WidgetContainer> getContainer();

    void setPos(float x, float y); // ��������� �������
    float getPosX();
    float getPosY();
    float getWidth();
    float getHeight();

    void setSize(float w, float h); // ������ �������. �������������� ��� ��� ������� � ��������������
    
    bool update(float); // ���������� ��������� �������
    
    virtual void render(); // ��������� ������� 

    void show(); // �������� ������
    void hide(); // ������ ������

    void processEvent(SDL_Event e);
    void addEventHandler(ptrSharedEventHandler); // ����������� ������ ��������� ������ ��� ��������� �������� �������. ��������� ��������� ��������� ��������������
    virtual ~Widget() {};

};

#endif