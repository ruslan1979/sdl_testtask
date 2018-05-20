#include "Client.h"

Client & Client::getInstance()
{	
	static Client c;
	return c;
}

void Client::run()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		throw runtime_error(string("SDL_Init Error: ") + SDL_GetError());

	SDL_Window *win = SDL_CreateWindow("I am an AWEMer!!!", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
	if (win == nullptr)
		throw runtime_error(string("SDL_CreateWindow Error: ") + SDL_GetError());

	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
		throw runtime_error(string("SDL_CreateRenderer Error: ") + SDL_GetError());

	sharedPtrWidget img(new Image("bitmap1.bmp", renderer));
	sharedPtrWidget img2(new Image("bitmap2.bmp", renderer));
	sharedPtrWidget btn(new Button("buttonon.bmp", "buttonoff.bmp", renderer));

	ptrSharedWidgetContainer  wc(new WidgetContainer(renderer));
	sharedPtrWidget img_wc2(new Image("bitmap3.bmp", renderer));
	sharedPtrWidget btn_wc2(new Button("buttonon2.bmp", "buttonoff2.bmp", renderer));

	ptrSharedWidgetContainer  wc2(new WidgetContainer(renderer));

	wc2->setSize(250, 400);
	wc2->setPos(10, 10);
	img_wc2->setSize(200, 200);
	img_wc2->setPos(20, 20);
	img_wc2->setId("img_wc2");
	btn_wc2->setSize(200, 50);
	btn_wc2->setPos(20, 300);
	btn_wc2->setId("btn_wc2");

	wc2->add(img_wc2);
	wc2->add(btn_wc2);
	wc2->setId("container2");
	wc2->hide();

	img->setPos(550, 280);
	img2->setPos(400, 400);
	btn->setPos(400, 200);
	btn->setId("btn1");
	img->setSize(200, 200);
	img->setId("img1");
	img->addEventHandler(ptrSharedEventHandler(new EventHandlerShowImage(img2)));
	btn->addEventHandler(ptrSharedEventHandler(new EventHandlerShowContainer(btn)));
	img2->setSize(100, 150);
	img2->setId("img2");
	img2->hide();
	wc->setPos(400, 150);
	wc->setSize(400, 400);

	wc->add(img);
	wc->add(btn);
	wc->add(img2);
	wc->add(wc2);

	// main loop
	while (1) {

		// event handling
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				break;
			else
			{
				wc->processEvent(e);
				wc2->processEvent(e);
			}
		}

		SDL_SetRenderDrawColor(renderer, 200, 50, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		wc->update(1);
		
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);	
}