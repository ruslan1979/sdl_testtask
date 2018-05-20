#include "EventHandler.h"
#include "WidgetContainer.h"
#include "Widget.h"

void EventHandlerShowImage::handleMouseEnter()
{
	auto w = getParam().lock();
	if (w == nullptr)
		return;

	auto wc = w->getContainer().lock();
	if (wc == nullptr)
		return;

	auto wid = wc->getWidget("img2").lock();
	if (wid == nullptr)
		return;

	wid->show();
}

void EventHandlerShowImage::handleMouseExit()
{
	auto w = getParam().lock();
	if (w == nullptr)
		return;

	auto wc = w->getContainer().lock();
	if (wc == nullptr)
		return;

	auto wid = wc->getWidget("img2").lock();
	if (wid == nullptr)
		return;

	wid->hide();
}

void EventHandlerShowContainer::handleLMouseUp()
{
	auto w = getParam().lock();
	if (w == nullptr)
		return;

	auto wc = w->getContainer().lock();
	if (wc == nullptr)
		return;

	auto wid = wc->getWidget("container2").lock();
	if (wc == nullptr)
		return;

	wid->isVisible() ? wid->hide() : wid->show();
}

weakPtrWidget EventHandler::getParam()
{
	return ptrWidgetParam;
}

EventHandler::EventHandler(sharedPtrWidget param)
{
	ptrWidgetParam = param;
};