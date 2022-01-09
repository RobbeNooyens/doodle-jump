/**
 *  ╒══════════════════════════════════════╕
 *  │                                      │
 *  │             Doodle Jump              │
 *  │        Advanced Programming          │
 *  │                                      │
 *  │            Robbe Nooyens             │
 *  │    s0201010@student.uantwerpen.be    │
 *  │                                      │
 *  │        University of Antwerp         │
 *  │                                      │
 *  ╘══════════════════════════════════════╛
 */

#ifndef DOODLEJUMP_TEXTVIEW_H
#define DOODLEJUMP_TEXTVIEW_H


#include <memory>

namespace wrappers {
    class TextWrapper;
}

class TextView {
public:
    ~TextView();

    const std::shared_ptr<wrappers::TextWrapper>& getText();

    void setPosition(double x, double y);
    void setText(const std::string& t);
    void setTextWrapper(std::shared_ptr<wrappers::TextWrapper>& wrapper);

private:
    std::shared_ptr<wrappers::TextWrapper> text;

};


#endif //DOODLEJUMP_TEXTVIEW_H
