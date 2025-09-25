#pragma once

#include <string>

namespace game_engine {
namespace primitives {

class IFont {
public:
    virtual ~IFont() {};

    virtual bool loadFromFile(const std::string& path) = 0;

};

}
}
