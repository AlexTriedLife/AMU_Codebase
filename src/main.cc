#include <iostream>
#include "file.h"
int main(int argc, char *argv[])
{
    amu::file::File f("text");
    std::cout << "Hello world!" << std::endl;
}
