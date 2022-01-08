//
// Created by robnoo on 8/01/22.
//

#ifndef DOODLEJUMP_TEXTCONTROLLER_H
#define DOODLEJUMP_TEXTCONTROLLER_H


#include <string>
#include <memory>

class TextView;
class WindowWrapper;
class TextWrapper;

namespace controllers {
    class TextController {
    public:
        TextController();
        ~TextController();

        void update(const std::string& s);
        void draw(std::shared_ptr<WindowWrapper> &window);

        void setPosition(double x, double y);
        void setTextWrapper(std::shared_ptr<TextWrapper> &wrapper);

    private:
        std::shared_ptr<TextView> view;
    };
}


#endif //DOODLEJUMP_TEXTCONTROLLER_H
