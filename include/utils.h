#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <SDL2/SDL.h>
#include "qblinalg/qbVector.h"




inline void PR(const char* file, int line) {
    const char* errorMessage = SDL_GetError();
    std::cout << "Error: " << errorMessage << " in file " << file << " at line " << line << std::endl;
}

#define PRINT_ERROR() PR(__FILE__, __LINE__)




#define QBVD qbVector<double>




#endif
