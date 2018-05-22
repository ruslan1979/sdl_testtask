#include "EventHandler.h"
#include "WidgetContainer.h"
#include "Widget.h"

EventHandler::EventHandler(sharedPtrWidget param)
{
    ptrWidgetParam = param;
};

weakPtrWidget EventHandler::getParam()
{
    return ptrWidgetParam;
}

void EventHandlerShowImage::setVisible(bool flag)
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

    flag ? wid-> show() : wid->hide();
}

void EventHandlerShowImage::handleMouseEnter()
{
    setVisible(true);
}

void EventHandlerShowImage::handleMouseExit()
{
    setVisible(false);
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


