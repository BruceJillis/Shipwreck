#include "Sprite.h"
#include "functions.h"

// constructor 
Sprite::Sprite() {
}

SDL_Surface* Sprite::Load(char* pFile) {
    SDL_Surface* image = NULL;
	if ((image = LoadImage(pFile)) == NULL) {
		return NULL;
	} 
	return image;
}


bool Sprite::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y) {
	if(dest == NULL || src == NULL) {
		return false;
	}
	SDL_Rect destR;
	destR.x = x;
	destR.y = y;
	
	SDL_BlitSurface(src, NULL, dest, &destR);
	return true;
}


bool Sprite::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x2, int y2, int width, int height) {
	if(dest == NULL || src == NULL) {
		return false;
	}
	SDL_Rect destR;
	destR.x = x;
	destR.y = y;
	
	SDL_Rect srcR;
	srcR.x = x2;
	srcR.y = y2;
	srcR.w = width;
	srcR.h = height;

	SDL_BlitSurface(src, &srcR, dest, &destR);
	return true;
}
