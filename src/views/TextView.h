//
// Created by robnoo on 8/01/22.
//

#ifndef DOODLEJUMP_TEXTVIEW_H
#define DOODLEJUMP_TEXTVIEW_H


#include <memory>

class TextWrapper;

class TextView {
public:
    ~TextView();

    const std::shared_ptr<TextWrapper>& getText();

    void setPosition(double x, double y);
    void setText(const std::string& t);
    void setTextWrapper(std::shared_ptr<TextWrapper>& wrapper);

private:
    std::shared_ptr<TextWrapper> text;

};


#endif //DOODLEJUMP_TEXTVIEW_H
