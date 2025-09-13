#pragma once

#include "Rect/Rect.hpp"
#include "Event.hpp"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

template<typename T>
static sf::Vector2<T> engineVector2ToSfVector2(const Vector2<T>& engineVec) {
    return { engineVec.x, engineVec.y };
}

template<typename T>
static Vector2<T> sfVector2ToEngineVector2(const sf::Vector2<T>& sfVec) {
    return { sfVec.x, sfVec.y };
}

template<typename T>
static Rect<T> sfRectToEngineRect(const sf::Rect<T>& sfRect) {
    return { sfRect.position.x, sfRect.position.y, sfRect.size.x, sfRect.size.y };
}

template<typename T>
static sf::Rect<T> engineRectToSfRect(const Rect<T>& engineRect) {
    return { engineVector2ToSfVector2(engineRect.getPosition()), engineVector2ToSfVector2(engineRect.getSize()) };
}

static KeyEvent::Key sfKeyCodeToEngineKeyCode(sf::Keyboard::Key sfKey) {
    const auto sfKeyCode = static_cast<int>(sfKey);
    return static_cast<KeyEvent::Key>(sfKeyCode);
}

static MouseEvent::Button sfMouseButtonToEngineMouseButton(sf::Mouse::Button sfMouseButton) {
    switch (sfMouseButton) {
        case sf::Mouse::Button::Left:
            return MouseEvent::Button::Left;
        case sf::Mouse::Button::Right:
            return MouseEvent::Button::Right;
        case sf::Mouse::Button::Middle:
            return MouseEvent::Button::Middle;
        default:
            return MouseEvent::Button::None;
    }
}

static std::unique_ptr<Event> sfEventToEngineEvent(const std::optional<sf::Event>& event) {
    if (!event.has_value()) {
        return nullptr;
    }

    const auto createKeyEvent = [](const auto& sfKey, KeyEvent::Action action) {
        auto engineKeyEvent = std::make_unique<KeyEvent>(sfKeyCodeToEngineKeyCode(sfKey->code), action);

        engineKeyEvent->setModifier(KeyEvent::Modifier::Alt, sfKey->alt);
        engineKeyEvent->setModifier(KeyEvent::Modifier::Control, sfKey->control);
        engineKeyEvent->setModifier(KeyEvent::Modifier::Shift, sfKey->shift);
        engineKeyEvent->setModifier(KeyEvent::Modifier::System, sfKey->system);

        return engineKeyEvent;
    };

    const auto createMouseEvent = [](const auto& sfMouseEvent, MouseEvent::Button button, MouseEvent::Action action) {
        return std::make_unique<MouseEvent>(sfVector2ToEngineVector2<int>(sfMouseEvent->position), button, action);
    };

    if (event->is<sf::Event::Closed>()) {
        return std::make_unique<Event>(Event::Type::Close);
    }
    else if (event->is<sf::Event::KeyPressed>()) {
        return createKeyEvent(event->getIf<sf::Event::KeyPressed>(), KeyEvent::Action::Press);
    }
    else if (event->is<sf::Event::KeyReleased>()) {
        return createKeyEvent(event->getIf<sf::Event::KeyReleased>(), KeyEvent::Action::Release);
    }
    else if (event->is<sf::Event::MouseButtonPressed>()) {
        const auto sfMouseEvent = event->getIf<sf::Event::MouseButtonPressed>();
        return createMouseEvent(sfMouseEvent, sfMouseButtonToEngineMouseButton(sfMouseEvent->button), MouseEvent::Action::Press);
    }
    else if (event->is<sf::Event::MouseButtonReleased>()) {
        const auto sfMouseEvent = event->getIf<sf::Event::MouseButtonReleased>();
        return createMouseEvent(sfMouseEvent, sfMouseButtonToEngineMouseButton(sfMouseEvent->button), MouseEvent::Action::Release);
    }
    else if (event->is<sf::Event::MouseMoved>()) {
        return createMouseEvent(event->getIf<sf::Event::MouseMoved>(), MouseEvent::Button::None, MouseEvent::Action::Move);
    }

    return nullptr;
}

}
}
