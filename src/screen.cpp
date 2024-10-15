#include "screen.h"
USE_NS_GRAPHICS;
Screen::Screen(const char *title, const uint16_t sw, const uint16_t sh)
    : SCREEN_TITLE(title),
      SCREEN_WIDTH(sh),
      SCREEN_HEIGHT(sw),
      m_glContext(nullptr),
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
    update();
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
  if (m_glContext) {
          SDL_GL_DestroyContext(m_glContext);
          m_glContext = nullptr;
  }
}
void Screen::update() {
  SDL_RenderClear(m_renderer);
  // Change color
  SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
  SDL_RenderPresent(m_renderer);
  SDL_Delay(1000 / 60);
}
bool Screen::init() {
  bool success = true;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Failed to initialize SDL. SDL Error: " << SDL_GetError()
              << "\n";
  }
  m_window = SDL_CreateWindow(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  if (!m_window) {
    std::cerr << "Failed to initialize window. SDL Error: " << SDL_GetError()
              << "\n";
    success = false;
  }
  m_glContext = SDL_GL_CreateContext(m_window);
  if (!m_glContext) {
    success = false;
  }

  m_renderer = SDL_CreateRenderer(m_window, NULL);
  if (!m_renderer) {
    std::cerr << "Failed to initialize renderer. SDL Error: " << SDL_GetError()
              << "\n";
    success = false;
  }

  return success;
}

uint16_t Screen::getScreenHeight() const { return SCREEN_HEIGHT; }
SDL_GLContext Screen::getGlContext() const { return m_glContext; }
SDL_Window *Screen::getWindow() const { return m_window; }
SDL_Renderer *Screen::getRenderer() const { return m_renderer; }
uint16_t Screen::getScreenWidth() const { return SCREEN_WIDTH; }
