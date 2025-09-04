#pragma once

#include "Interface/SpriteFactory.h"

namespace game_engine {
namespace primitives {

class ISprite;

class Sprite {
public:
    Sprite();

private:
    std::unique_ptr<ISprite> m_impl;
};

}
}
