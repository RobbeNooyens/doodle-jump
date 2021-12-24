//
// Created by robnoo on 24/12/21.
//

#ifndef DOODLEJUMP_TEXTURENOTFOUNDEXCEPTION_H
#define DOODLEJUMP_TEXTURENOTFOUNDEXCEPTION_H


#include "Exception.h"

class TextureNotFoundException: public Exception {
public:
    explicit TextureNotFoundException(std::string& textureFile);

};


#endif //DOODLEJUMP_TEXTURENOTFOUNDEXCEPTION_H
