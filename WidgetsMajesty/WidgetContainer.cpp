#include "WidgetContainer.h"


WidgetContainer::WidgetContainer(SDL_Renderer *renderer) : Widget(renderer), widgets(), vWidgets() {
	this->renderer = renderer;
}

//clean objects during closing
WidgetContainer::~WidgetContainer(void) {
	auto it = widgets.begin(), end = widgets.end();
	for (; it != end; ++it) {
		it->second.reset();
	}

	vWidgets.clear();
	auto vit = vWidgets.begin(), vend = vWidgets.end();
	for (; vit != vend; ++vit) {
		vit->reset();
	}
	vWidgets.clear();
}

bool orderCompare(const sharedPtrWidget w1, const sharedPtrWidget w2) {
	return w1->getOrder() < w2->getOrder();
}

void WidgetContainer::add(sharedPtrWidget w)
{	
	bool insertRes = widgets.insert({ w->getId(), w }).second;
	if (!insertRes)
		throw logic_error("exception: " + w->getId() + " already in use!");
		
	vWidgets.push_back(w);
	w->setContainer(shared_from_this());
	stable_sort(vWidgets.begin(), vWidgets.end(), orderCompare);
}

void WidgetContainer::update(float dt)
{
	Widget::render();
	for (auto w : vWidgets) {
		w->update(dt);
	}
}

weakPtrWidget  WidgetContainer::getWidget(string widgetId)
{
	try {
		return widgets.at(widgetId);
	}
	catch (const std::out_of_range& e) {
		cout << "The widget is out of range: " << e.what();
	}
}

void WidgetContainer::processEvent(SDL_Event evt)
{
	if (!isVisible()) 
		return;

	for (auto w : vWidgets)
		w->processEvent(evt);
}

void WidgetContainer::render()
{
	Widget::render();
	if (!isVisible()) 
		return;

	if (vWidgets.size() == 0) 
		return;

	for (auto w : vWidgets) {
		w->render();
	}
}