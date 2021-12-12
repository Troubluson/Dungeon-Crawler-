#ifndef _TEXT_CLASS_
#define _TEXT_CLASS_

#include "entity.hpp"

class ScreenText : public Entity {
public:
    ScreenText(const std::string& textLocation, sf::Vector2f textPos, sf::Vector2f textDims);
    ~ScreenText() { }

private:
};

#endif