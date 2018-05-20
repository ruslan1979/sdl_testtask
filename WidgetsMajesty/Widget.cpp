#include "Widget.h"

//private method
bool Widget::isCursorInside(int x, int y) {
	int diffx = x - (int)posX;
	int diffy = y - (int)posY;
	return (diffx > 0) && (diffx <= (int)width) &&
		(diffy > 0) && (diffy <= (int)height);
}

Widget::Widget(SDL_Renderer *renderer) {
	initWidget();
	this->renderer = renderer;
}

void Widget::initWidget()
{
	id = "";
	posX = 0;
	posY = 0;
	width = 220;
	height = 70;
	visible = true;
	order = 0;
}

void Widget::setId(const std::string & id)
{
	this->id = id;
}

string Widget::getId()
{
	return id;
}

void Widget::setOrder(int order)
{
	order = order;
}

void Widget::setPos(float x, float y)
{
	posX = x;
	posY = y;
}

float Widget::getPosX()
{
	return posX;
}

float Widget::getPosY()
{
	return posY;
}

float Widget::getWidth()
{
	return width;
}

float Widget::getHeight(){
	return height;
}

void Widget::setSize(float w, float h)
{
	width = w;
	height = h;
}

void Widget::onPressLMouseButton(void)
{
	for (auto evt : ptrHandlers)
		evt->handleLMouseDown();
}

void Widget::onReleaseLMouseButton(void)
{
	for (auto evt : ptrHandlers)
		evt->handleLMouseUp();
}

void Widget::onEnterLMouseButton(void)
{
	for (auto evt : ptrHandlers)
		evt->handleMouseEnter();
}

void Widget::onLeaveLMouseButton(void)
{
	for (auto evt : ptrHandlers)
		evt->handleMouseExit();
}

bool Widget::update(float dt)
{
	if (!visible)
		return false;
	
	setPos(posX, posY);
	setSize(width, height);
	render();
}

void Widget::render()
{	
	SDL_Rect rect;
	rect.x = (int)posX;
	rect.y = (int)posY;
	rect.w = (int)width;
	rect.h = (int)height;
	SDL_SetRenderDrawColor(this->renderer, 100, 200, 100, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(this->renderer, &rect);
}

void Widget::show()
{
	visible = true;
}

void Widget::hide()
{
	visible = false;
}

void Widget::addEventHandler(boost::shared_ptr<EventHandler> evt)
{
	ptrHandlers.push_back(evt);
}

void Widget::processEvent(SDL_Event evt)
{
	if ((evt.button.button == SDL_BUTTON_LEFT) && 
		isCursorInside(evt.button.x, evt.button.y) ) {
		if (evt.type == SDL_MOUSEBUTTONDOWN)
			onPressLMouseButton();
		if (evt.type == SDL_MOUSEBUTTONUP)
			onReleaseLMouseButton();
	}
	if (evt.type == SDL_MOUSEMOTION) {
		if (isCursorInside(evt.motion.x, evt.motion.y) &&
			!isCursorInside(evt.motion.x - evt.motion.xrel, evt.motion.y - evt.motion.yrel))
			onEnterLMouseButton();
		if (!isCursorInside(evt.motion.x, evt.motion.y) &&
			isCursorInside(evt.motion.x - evt.motion.xrel, evt.motion.y - evt.motion.yrel))
			onLeaveLMouseButton();
	}
}

bool Widget::isVisible() { 
	return visible; 
}

void Widget::setContainer(ptrSharedWidgetContainer ptr)
{
	ptrWidgetContnr = ptr;
}

boost::weak_ptr<WidgetContainer> Widget::getContainer()
{
	return  ptrWidgetContnr;
}

int Widget::getOrder() { 
	return order; 
}