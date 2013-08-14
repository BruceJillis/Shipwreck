#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Vector2.h"

inline SDL_Surface* LoadImage(char* filename ) {
    SDL_Surface* loaded = NULL;
    SDL_Surface* optimized = NULL;
    loaded = IMG_Load(filename);
    if ( loaded != NULL ) {
		// resample to screens bpp
        optimized = SDL_DisplayFormatAlpha(loaded);
        // free the old image
        SDL_FreeSurface(loaded);
    }
    return optimized;
}

inline float RandomFloatRange(float min, float max) {
	return min + (float)rand() / ((float)RAND_MAX/(max - min));
}
#endif






