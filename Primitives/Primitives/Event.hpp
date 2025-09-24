#pragma once

#include <bitset>

#include "Vector2.hpp"

namespace game_engine {
namespace primitives {

class Event {
public:
    enum class Type {
        Unknown,
        Mouse,
        Keyboard,
        Close
    };

    Event(Type type = Type::Unknown) : m_type(type) {};
    virtual ~Event() = default;

    Type type() const { return m_type; }

    template<typename T>
    T* as() {
        return dynamic_cast<T*>(this);
    }

    template<typename T>
    const T* as() const {
        return dynamic_cast<const T*>(this);
    }

protected:
    Type m_type;
};

class MouseEvent : public Event {
public:
    enum class Button {
        Left,
        Right,
        Middle,
        None
    };

    enum class Action {
        Press,
        Release,
        Move
    };

    MouseEvent(const Vector2i& pos, Button button, Action action) : Event(Type::Mouse), m_pos(pos), m_button(button), m_action(action) {
        updateCurrentButton();
    }

    Vector2i position() const { return m_pos; };
    Button button() const { return m_button; };
    Action action() const { return m_action; };

    static bool isButtonPressed(Button button) { return button != Button::None && s_buttonStates.test(static_cast<int>(button)); }

private:
    Vector2i m_pos;
    Button m_button;
    Action m_action;

    inline static std::bitset<16> s_buttonStates;

    void updateCurrentButton() {
        if (m_button != Button::None) {
            if (m_action == Action::Press) {
                s_buttonStates.set(static_cast<int>(m_button));
            }
            else if (m_action == Action::Release) {
                s_buttonStates.reset(static_cast<int>(m_button));
            }
        }
    }
};

class KeyEvent : public Event {
public:
    enum class Action {
        Press,
        Release
    };

    enum class Key {
        Unknown = -1,
        A = 0,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        Num0,
        Num1,
        Num2,
        Num3,
        Num4,
        Num5,
        Num6,
        Num7,
        Num8,
        Num9,
        Escape,
        LControl,
        LShift,
        LAlt,
        LSystem,
        RControl,
        RShift,
        RAlt,
        RSystem,
        Menu,
        LBracket,
        RBracket,
        Semicolon,
        Comma,
        Period,
        Apostrophe,
        Slash,
        Backslash,
        Grave,
        Equal,
        Hyphen,
        Space,
        Enter,
        Backspace,
        Tab,
        PageUp,
        PageDown,
        End,
        Home,
        Insert,
        Delete,
        Add,
        Subtract,
        Multiply,
        Divide,
        Left,
        Right,
        Up,
        Down,
        Numpad0,
        Numpad1,
        Numpad2,
        Numpad3,
        Numpad4,
        Numpad5,
        Numpad6,
        Numpad7,
        Numpad8,
        Numpad9,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        F13,
        F14,
        F15,
        Pause,
        MaxKeyValue = 255
    };

    enum Modifier {
        NoModifier   = 0x00,
        Shift        = 0x01,
        Control      = 0x02,
        Alt          = 0x04,
        System       = 0x08
    };


    KeyEvent(Key key, Action action, uint8_t modifiers = NoModifier) : Event(Type::Keyboard), m_key(key), m_action(action), m_modifiers(modifiers) {
        updateCurrentKey();
    }

    bool hasModifier(Modifier modifier) const { return (m_modifiers & modifier) != 0; }
    void setModifier(Modifier modifier, bool enabled = true) {
         if (enabled) {
             m_modifiers |= modifier;
         }
         else {
             m_modifiers &= ~modifier;
         }
     }

    Key key() const { return m_key; }
    Action action() const { return m_action; }
    uint8_t modifiers() const { return m_modifiers; }

    static bool isKeyPressed(Key key) { return key != Key::Unknown && s_keyStates.test(static_cast<int>(key)); }

private:
    Key m_key;
    Action m_action;
    uint8_t m_modifiers;

    inline static std::bitset<256> s_keyStates;

    void updateCurrentKey() {
        if (m_key != Key::Unknown) {
            if (m_action == Action::Press) {
                s_keyStates.set(static_cast<int>(m_key));
            }
            else if (m_action == Action::Release) {
                s_keyStates.reset(static_cast<int>(m_key));
            }
        }
    }
};

}
}
