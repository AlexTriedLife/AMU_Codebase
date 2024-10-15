#include "file.h"

USE_NS_FILE;

File::File(std::string filename)
    : m_filename(filename),
      m_contents_stream(m_filename),
      m_file(m_filename, std::ios::in) {}

File::~File() {}

void File::createFile() {
        if (!m_file.is_open()) {
                std::cout << "failed to open\n";
        }
}
