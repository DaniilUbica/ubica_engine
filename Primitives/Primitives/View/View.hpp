#pragma once

#include "Rect.hpp"
#include "ViewFactory.hpp"

namespace game_engine {
namespace primitives {

class View {
public:
    View(const FloatRect& viewRect) : m_impl(createView(viewRect)) {};

    void setSize(const Vector2f& size) { m_impl->setSize(size); };
    void setCenter(const Vector2f& center) { m_impl->setCenter(center); };

    FloatRect getViewRect() const { return m_impl->getViewRect(); };

private:
    std::shared_ptr<IView> m_impl;
};

}
}
