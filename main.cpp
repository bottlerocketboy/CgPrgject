//#include <iostream>
#include <SDL.h>
#include <stdio.h>

#define GAME_NAME "MyRPG"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Window contains screen surface...
SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gImg = NULL;


bool InitSDL(){

	bool success = false;

	//Sets up SDL...
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL could not initialize!"\
			"SDL_Error: %s\n", SDL_GetError());
	}
	else {
		gWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		//Failed to setup window...
		if (gWindow == NULL){
			printf("SDL could not create window!"\
				"SDL_Error: %s\n", SDL_GetError());
		}
		else{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			success = true;
		}
	}

	return success;
}

void CloseSDL(){
	//Deallocate surface memory...
	SDL_FreeSurface(gImg);
	gImg = NULL;

	//Destroy window...
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

bool LoadMedia(){
	bool success = true;
	const char* imgName = "panda.bmp";

	gImg = SDL_LoadBMP(imgName);
	if (gImg == NULL){
		printf("Image %s failed to laod!", imgName);
		success = false;
	}

	return success;
}

void Render(float deltaTime){

}

void Update(float deltaTime){

}

int main(int argc, char* args[]){
	if (InitSDL() && LoadMedia()){
		//bool gameRunning = true;

		//while (gameRunning){
		//	//TODO: Calculate actual deltatime...
		//	float deltaTime = 0.00f;

		//	Render(deltaTime);
		//	Update(deltaTime);
		//}

		SDL_BlitSurface(gImg, NULL, gScreenSurface, NULL);
		SDL_UpdateWindowSurface(gWindow);

		SDL_Delay(10000);
	}

	//Free resources and close SDL
	CloseSDL();

	return 0;
}