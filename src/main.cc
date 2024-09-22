#include <iostream>
#include "screen.h"
int main(int argc, char *argv[])
{
    amu::graphics::Screen screen("Screen test", 800, 600);
    screen.run();
}
