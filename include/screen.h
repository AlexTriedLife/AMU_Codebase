#ifndef SCREEN_H
#define SCREEN_H
#include <SDL3/SDL.h>

#include <iostream>
#include <memory>

#include "defines.h"

NS_AMU_BEGINS
NS_GRAPHICS_BEGINS

class Screen {
       public:
        Screen(const char *title, const uint16_t SCREEN_WIDTH,
               const uint16_t SCREEN_HEIGHT);
        ~Screen();
        void run();

       private:
        void clean();
        bool init();
        SDL_Renderer *m_renderer;
        SDL_Window *m_window;
        const uint16_t SCREEN_WIDTH;
        const uint16_t SCREEN_HEIGHT;
        const char *SCREEN_TITLE;

        // Getters
       public:
        uint16_t getScreenWidth();
        uint16_t getScreenHeight();
};

NS_ENDS      // graphics
    NS_ENDS  // amu
#endif       // SCREEN_H
