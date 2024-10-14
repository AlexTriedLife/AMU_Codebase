#include "screen.h"
USE_NS_GRAPHICS;
Screen::Screen(const char *title, const uint16_t sw, const uint16_t sh)
    : SCREEN_TITLE(title),
      SCREEN_WIDTH(sh),
      SCREEN_HEIGHT(sw),
      m_window(nullptr),
      m_renderer(nullptr) {}
Screen::~Screen() { clean(); }
void Screen::run() {
        bool isRunning{true};
        if (!init()) {
                std::cerr << "failed to initialize screen\n";
                isRunning = false;
        }
        while (isRunning) {
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_EVENT_QUIT) {
                                isRunning = false;
                        }

                }
                    	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
                        SDL_RenderClear(m_renderer);

                        SDL_RenderPresent(m_renderer);
        }
        clean();
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
void Screen::update() {
        SDL_RenderClear(m_renderer);
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
        // Define a rectangle
        SDL_FRect rect{};
        rect.x = SCREEN_WIDTH / 4;
        rect.y = SCREEN_HEIGHT / 4;
        rect.w = SCREEN_WIDTH / 2;
        rect.h = SCREEN_HEIGHT / 2;
        SDL_RenderFillRect(m_renderer, &rect);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(1000 / 60);
        std::cout << "Rendering\n";


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


uint16_t Screen::getScreenHeight() const { return SCREEN_HEIGHT; }
SDL_Window *Screen::getWindow() const { return m_window; }
SDL_Renderer *Screen::getRenderer() const { return m_renderer; }
uint16_t Screen::getScreenWidth() const { return SCREEN_WIDTH; }