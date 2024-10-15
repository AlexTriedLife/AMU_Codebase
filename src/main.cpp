#include <iostream>

#include "screen.h"
#include "wave.h"
int main(int argc, char *argv[]) {
  amu::graphics::Screen screen("Screen test", 800, 600);

  amu::audio::Wave wave(400.0, 300.0, 100.0, 50.0);
  std::cout << wave.getAmplitude() << "\n";
  screen.run();
}
