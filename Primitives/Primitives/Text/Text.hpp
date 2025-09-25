#pragma once

#include "TextFactory.hpp"
#include "Font/Font.hpp"

namespace game_engine {
namespace primitives {

class Text : public Drawable {
public:
    Text(const Font& font, const std::string& text = "", uint size = 32) : m_impl(createText(font.m_impl)) {
        setText(text);
        setSize(size);
    };

    void setText(const std::string& text) { m_impl->setText(text); };
    void setPosition(const Vector2f& pos) { m_impl->setPosition(pos); };
    void setSize(uint size) { m_impl->setSize(size); };
    void setFillColor(const Color& color) { m_impl->setFillColor(color); };

    [[nodiscard]] Vector2f getPosition() const { return m_impl->getPosition(); };

    void draw(const RenderWindow& window) override { window.draw(*this); };

private:
    
    std::shared_ptr<IDrawable> drawableImpl() const override { return m_impl; };

    std::shared_ptr<IText> m_impl;
};

}
}
