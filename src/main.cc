#include <iostream>


#include "screen.h"
#include "util_time.h"
int main(int argc, char *argv[]) {
        std::cout << "current time: " << amu::util::now() << "\n";
        amu::graphics::Screen screen("Screen test", 800, 600);
        screen.run();
}
