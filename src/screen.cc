#include "screen.h"
USE_NS_GRAPHICS;
Screen::Screen(const char *title, const uint16_t sw, const uint16_t sh)
    : SCREEN_TITLE(title),
      SCREEN_WIDTH(sh),
      SCREEN_HEIGHT(sw),
      m_window(nullptr),
      m_renderer(nullptr) {
        if (!init()) {
                std::cerr << "Screen failed to initialize" << std::endl;
        } else {
                std::cout << "initialized" << std::endl;
        }
}
Screen::~Screen() {}
void Screen::run() {
        bool isRunning{true};

        while (isRunning) {
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_EVENT_QUIT) {
                                isRunning = false;
                        }
                }
        }
        clean();
        SDL_QuitEvent();
        SDL_Quit();
}
void Screen::clean() {
        if (m_window) {
                SDL_DestroyWindow(m_window);
                m_window = nullptr;
        }
        if (m_renderer) {
                SDL_DestroyRenderer(m_renderer);
                m_renderer = nullptr;
        }
}
bool Screen::init() {
        bool success = true;
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                std::cerr << "Failed to initialize SDL. SDL Error: "
                          << SDL_GetError() << "\n";
        }
        m_window = SDL_CreateWindow(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT,
                                    SDL_WINDOW_RESIZABLE);

        if (!m_window) {
                std::cerr << "Failed to initialize window. SDL Error: "
                          << SDL_GetError() << "\n";
                success = false;
        } else {
                m_renderer = SDL_CreateRenderer(m_window, NULL);
        }

        if (!m_renderer) {
                std::cerr << "Failed to initialize renderer. SDL Error: "
                          << SDL_GetError() << "\n";
                success = false;
        }

        return success;
}
