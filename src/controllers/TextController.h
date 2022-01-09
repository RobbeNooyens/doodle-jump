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

#ifndef DOODLEJUMP_TEXTCONTROLLER_H
#define DOODLEJUMP_TEXTCONTROLLER_H


#include <string>
#include <memory>

class TextView;

namespace wrappers {
    class WindowWrapper;
    class TextWrapper;
}

namespace controllers {
    class TextController {
    public:
        TextController();
        ~TextController();

        void update(const std::string& s);
        void draw(std::shared_ptr<wrappers::WindowWrapper> &window);

        void setPosition(double x, double y);
        void setTextWrapper(std::shared_ptr<wrappers::TextWrapper> &wrapper);

    private:
        std::shared_ptr<TextView> view;
    };
}


#endif //DOODLEJUMP_TEXTCONTROLLER_H
