#pragma once

#include "FontFactory.hpp"

namespace game_engine {
namespace primitives {

class Font {
    friend class Text;
public:
    Font() : m_impl(createFont()) {};
    Font(const std::string& path) { m_impl = createFont(); m_impl->loadFromFile(path); };

    [[nodiscard]] bool loadFromFile(const std::string& path) { return m_impl->loadFromFile(path); };

private:
    std::shared_ptr<IFont> m_impl;
};

}
}
