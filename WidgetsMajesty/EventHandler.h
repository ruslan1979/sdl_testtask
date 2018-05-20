#pragma once
#include <vector>

class Widget;
#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp"

typedef boost::shared_ptr<Widget> sharedPtrWidget;
typedef boost::weak_ptr<Widget> weakPtrWidget;

class EventHandler {	
protected:
	weakPtrWidget ptrWidgetParam;
	weakPtrWidget getParam();
public:
	EventHandler(sharedPtrWidget param);
	virtual void handleLMouseDown() {};
	virtual void handleLMouseUp() {};
	virtual void handleMouseEnter() {};
	virtual void handleMouseExit() {};
	virtual ~EventHandler() = default;
};

class EventHandlerShowImage : public EventHandler {
	using EventHandler::EventHandler;
	virtual void handleMouseEnter();
	virtual void handleMouseExit();
};

 class EventHandlerShowContainer : public EventHandler {
	using EventHandler::EventHandler;
	virtual void handleLMouseUp();

};