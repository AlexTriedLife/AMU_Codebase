#ifndef SCREEN_H
#define SCREEN_H
#include "defines.h"
#include <SDL3/SDL.h>
#include <iostream>
#include <memory>
NS_AMU_BEGINS
NS_GRAPHICS_BEGINS

class Screen
{
public:
    Screen(const char *title, const uint16_t SCREEN_WIDTH, const uint16_t SCREEN_HEIGHT);
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


};

NS_GRAPHICS_ENDS
NS_AMU_ENDS
#endif //SCREEN_H
