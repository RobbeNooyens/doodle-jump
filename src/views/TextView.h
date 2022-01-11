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

/**
 * @brief Represents text rendering
 */
class TextView {
public:
    /**
     * @brief Destructor
     */
    ~TextView();

    /**
     * @return current textwrapper
     */
    const std::shared_ptr<wrappers::TextWrapper>& getText();

    /**
     * @param x new x coordinate
     * @param y new y coordinate
     */
    void setPosition(double x, double y);
    /**
     * @param t string to display
     */
    void setText(const std::string& t);
    /**
     * @param wrapper wrapper to use for rendering
     */
    void setTextWrapper(std::shared_ptr<wrappers::TextWrapper>& wrapper);

private:
    std::shared_ptr<wrappers::TextWrapper> text{};

};


#endif //DOODLEJUMP_TEXTVIEW_H
