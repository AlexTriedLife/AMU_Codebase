/**
 * @file file.h
 * @author Alex McPherson Uribe
 * @brief A wrapper for files 
 * @version 0.1
 * @date 2024-09-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef FILE_H
#define FILE_H

#include "defines.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
NS_AMU_BEGINS
NS_FILE_BEGINS
class File
{
public:
    File(std::string filename);
    ~File();
    void createFile();

private:
    std::string m_filename;
    std::stringstream m_contents_stream;
    std::string m_contents;
    std::fstream m_file;

};

NS_FILE_ENDS
NS_AMU_ENDS

/* code */
#endif 
