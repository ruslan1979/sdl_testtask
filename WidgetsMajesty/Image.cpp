#include "Image.h"

Image::Image(const std::string imageFilePath, SDL_Renderer *renderer) : Widget(renderer)
{
	SDL_Surface *loadingSurf = SDL_LoadBMP(imageFilePath.c_str());
	if (loadingSurf == nullptr)
		throw runtime_error(string("SDL_LoadBMP error: ") + SDL_GetError());

	imageTex = SDL_CreateTextureFromSurface(renderer, loadingSurf);
	SDL_FreeSurface(loadingSurf);	

	this->renderer = renderer;
}

void Image::render()
{
	if ((this->renderer == nullptr) || (imageTex == nullptr))
		return;

	if (!isVisible()) return;

	doRender();
}

void Image::doRender()
{
	SDL_Rect rect;
	rect.x = (int)getPosX();
	rect.y = (int)getPosY();
	rect.w = (int)getWidth();
	rect.h = (int)getHeight();

	SDL_RenderCopy(this->renderer, imageTex, NULL, &rect);
}

Image::~Image()
{
	if (imageTex != nullptr)
		SDL_DestroyTexture(imageTex);
}