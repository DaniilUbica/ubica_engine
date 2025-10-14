#pragma once

#include <memory>

namespace game_engine {
namespace cpplib {

template<typename T>
class singletone_from_this {
public:
    static std::shared_ptr<T> instance() {
        if (const auto sp = m_instance.lock()) {
            return sp;
        }

        const auto sp = std::shared_ptr<T>(new T());
        m_instance = sp;

        return sp;
    }

    template<typename... Args>
    static std::shared_ptr<T> instance(Args&&... args) {
        if (const auto sp = m_instance.lock()) {
            return sp;
        }

        const auto sp = std::shared_ptr<T>(new T(std::forward<Args>(args)...));
        m_instance = sp;

        return sp;
    }

    singletone_from_this(const singletone_from_this&) = delete;
    void operator=(const singletone_from_this&) = delete;
    singletone_from_this(singletone_from_this&&) = delete;
    void operator=(singletone_from_this&&) = delete;

protected:
    singletone_from_this() = default;

private:
    inline static std::weak_ptr<T> m_instance;
};

}
}
