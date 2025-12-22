/*I have very little idea if this works or not 
I cannot test this on either my windows nor my linux machines
I've checked this using copilot and GPT
Both show that the code is correct and should work*/

#include <iostream>
#include <cstdlib>
#include "SDL.h"
#include <SDL_image.h>

using namespace std;

int main(int argv, char** argc)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cerr << "Unable to initialize SDL" << SDL_GetError() << endl;

		return -1;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		cerr << "Unable to initialize SDL_image" << IMG_GetError() << endl;
		return -1;
	}

	atexit(IMG_Quit);

	atexit(SDL_Quit);


	SDL_Window* window = SDL_CreateWindow(
		"VGP122_L07_Al-Malki_Wael",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_SHOWN
	);

	if (!window)
	{
		cerr << "Unable to create window: " << SDL_GetError() << endl;
		return -1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED
	);

	if (!renderer)
	{
		cerr << "Unable to create renderer: " << SDL_GetError() << endl;
		return -1;
	}

	SDL_Surface* bgSurface = IMG_Load("images/bg.png");
	SDL_Surface* logoSurface = IMG_Load("images/logo.png");
	SDL_Surface* playSurface = IMG_Load("images/play.png");

	if (!bgSurface || !logoSurface || !playSurface)
	{
		cerr << "Unable to load image: " << IMG_GetError() << endl;
		return -1;
	}

	SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
	SDL_Texture* logoTexture = SDL_CreateTextureFromSurface(renderer, logoSurface);
	SDL_Texture* playTexture = SDL_CreateTextureFromSurface(renderer, playSurface);

	SDL_FreeSurface(bgSurface);
	SDL_FreeSurface(logoSurface);
	SDL_FreeSurface(playSurface);

	bool isRunning = true;
	SDL_Event event;

	while (isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
		}
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, bgTexture, NULL, NULL);
		SDL_Rect logoRect = { 200, 50, 400, 150 };
		SDL_RenderCopy(renderer, logoTexture, NULL, &logoRect);
		SDL_Rect playRect = { 300, 300, 200, 100 };
		SDL_RenderCopy(renderer, playTexture, NULL, &playRect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(bgTexture);
	SDL_DestroyTexture(logoTexture);
	SDL_DestroyTexture(playTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);



	cout << "SDL initialized" << endl;

	return 0;
}