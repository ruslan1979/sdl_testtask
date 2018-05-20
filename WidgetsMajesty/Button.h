#pragma once
#include "Widget.h"

using namespace std;

class Button :	public Widget{
private :
	bool pressed;
	SDL_Texture *onImageTex;
	SDL_Texture *offImageTex;
	SDL_Renderer *renderer;

protected:
	virtual void onPressLMouseButton(void);	
	virtual void onReleaseLMouseButton(void);

public:
	Button(const std::string onImageFilePath, const std::string offImageFilePath, SDL_Renderer *renderer);
	void setPressed(bool pressed);
	virtual void render();
	virtual void doRender();
	~Button();
};