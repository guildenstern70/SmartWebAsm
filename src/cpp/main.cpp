#include <iostream>
#include <SDL/SDL.h>

void showColoredCube() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen = SDL_SetVideoMode(256, 256, 32, SDL_SWSURFACE);

#ifdef TEST_SDL_LOCK_OPTS
    EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
#endif

    if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
#ifdef TEST_SDL_LOCK_OPTS
            // Alpha behaves like in the browser, so write proper opaque pixels.
      int alpha = 255;
#else
            // To emulate native behavior with blitting to screen, alpha component is ignored. Test that it is so by outputting
            // data (and testing that it does get discarded)
            int alpha = (i+j) % 255;
#endif
            *((Uint32*)screen->pixels + i * 256 + j) = SDL_MapRGBA(screen->format, i, j, 255-i, alpha);
        }
    }
    if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
    SDL_Flip(screen);

    std::cout << "You should see a smoothly-colored square - no sharp lines but the square borders!" << std::endl;

    //SDL_Quit();
}

int main() {
    std::cout << "Welcome to SmartWebAsm!" << std::endl  << std::endl;
    showColoredCube();
    return 0;
}

