#include "Button.h"

void Button::onPressLMouseButton(void)
{	
	Widget::onPressLMouseButton();
	setPressed(true);	
}

void Button::onReleaseLMouseButton(void)
{	
	Widget::onReleaseLMouseButton();
	setPressed(false);	
}

Button::Button(const std::string onImageFilePath, const std::string offImageFilePath, SDL_Renderer *renderer) : Widget(renderer), pressed(false) {
	SDL_Surface *loadingSurf = SDL_LoadBMP(onImageFilePath.c_str());
	if (loadingSurf == nullptr) 
		throw runtime_error(string("SDL_LoadBMP error: ") + SDL_GetError());

	onImageTex = SDL_CreateTextureFromSurface(renderer, loadingSurf);
	SDL_FreeSurface(loadingSurf);
	
	loadingSurf = SDL_LoadBMP(offImageFilePath.c_str());
	if (loadingSurf == nullptr)
		throw runtime_error(string("SDL_LoadBMP error: ") + SDL_GetError());
	
	offImageTex = SDL_CreateTextureFromSurface(renderer, loadingSurf);
	SDL_FreeSurface(loadingSurf);	

	this->renderer = renderer;
}

void Button::setPressed(bool pressed)
{
	this->pressed = pressed;
}

void Button::render()
{
	if ((this->renderer == nullptr) || (onImageTex == nullptr) || (offImageTex == nullptr))
		return;

	doRender();
}

void Button::doRender()
{
	SDL_Rect rect;
	rect.x = (int)getPosX();
	rect.y = (int)getPosY();
	rect.w = (int)getWidth();
	rect.h = (int)getHeight();
	if (pressed)
		SDL_RenderCopy(this->renderer, onImageTex, nullptr, &rect);
	else
		SDL_RenderCopy(this->renderer, offImageTex, nullptr, &rect);
}

Button::~Button()
{
	SDL_DestroyTexture(onImageTex);
	SDL_DestroyTexture(offImageTex);
}