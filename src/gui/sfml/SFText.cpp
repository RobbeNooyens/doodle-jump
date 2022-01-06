//
// Created by robnoo on 6/01/22.
//

#include "SFText.h"

bool SFText::fontInitialized = false;

SFText::SFText(const std::string& content, unsigned int size) {
    text.setString(content);
    text.setCharacterSize(size);
}
