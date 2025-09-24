#pragma once

namespace game_engine {
namespace primitives {

class IView {
public:
    virtual ~IView() {};

    virtual void setSize(const Vector2f& size) = 0;
    virtual void setCenter(const Vector2f& center) = 0;

    virtual FloatRect getViewRect() const = 0;
};

}
}
