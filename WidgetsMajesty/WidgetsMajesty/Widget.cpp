#include "Widget.h"

void Widget::setId(const string & id)
{
	widgetId = id;
}

void Widget::setOrder(int order)
{
	widgetOrder = order;
}

void Widget::setPos(float x, float y)
{
	widgetX = x;
	widgetY = y;
}

void Widget::setSize(float w, float h)
{
	widgetW = w;
	widgetH = h;
}

void Widget::onPressLMouseButton(void)
{
	EventHandler::handleEvent(SDL_MouseMotionEvent);
}

void Widget::onReleaseLMouseButton(void)
{
}

void Widget::onEnterLMouseButton(void)
{
}

void Widget::onLeaveLMouseButton(void)
{
}

bool Widget::update(float dt)
{
	return false;
}

void Widget::render(void)
{
}

void Widget::show()
{
}

void Widget::hide()
{
}

void Widget::addEventHandler(EventHandler* eh)
{
	widgetHandlers.insert(eh);
}
