#pragma once

#include <string>

namespace game_engine {
namespace primitives {

class ITexture {
public:
    virtual ~ITexture() {};

    virtual bool loadFromFile(const std::string& path) = 0;
};

}
}
