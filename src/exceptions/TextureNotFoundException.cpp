//
// Created by robnoo on 24/12/21.
//

#include "TextureNotFoundException.h"

TextureNotFoundException::TextureNotFoundException(std::string &textureFile): Exception("Couldn't load texture: " + textureFile) {

}
