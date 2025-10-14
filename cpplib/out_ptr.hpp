#include <memory>
#include <type_traits>
#include <utility>

namespace game_engine {
namespace cpplib {

template<typename SmartPtr>
class out_ptr_t {
private:
    SmartPtr& m_ptr;

public:
    explicit out_ptr_t(SmartPtr& ptr) noexcept : m_ptr(ptr) {}
    
    template<typename T>
    operator T**() noexcept {
        static_assert(std::is_pointer_v<T*>, "T must be a pointer type");
        m_ptr.reset();
        return reinterpret_cast<T**>(&m_ptr);
    }
    
    operator void**() noexcept {
        m_ptr.reset();
        return reinterpret_cast<void**>(&m_ptr);
    }
    
    out_ptr_t(const out_ptr_t&) = delete;
    out_ptr_t& operator=(const out_ptr_t&) = delete;
};

template<typename SmartPtr>
out_ptr_t<SmartPtr> out_ptr(SmartPtr& ptr) noexcept {
    return out_ptr_t<SmartPtr>(ptr);
}

template<typename T>
class out_ptr_t<std::shared_ptr<T>> {
private:
    std::shared_ptr<T>& m_ptr;
    T* m_raw_ptr;

public:
    explicit out_ptr_t(std::shared_ptr<T>& ptr) noexcept 
        : m_ptr(ptr), m_raw_ptr(nullptr) {
        m_ptr.reset();
    }
    
    ~out_ptr_t() {
        if (m_raw_ptr) {
            m_ptr.reset(m_raw_ptr);
        }
    }
    
    operator T**() noexcept {
        return &m_raw_ptr;
    }
    
    operator void**() noexcept {
        return reinterpret_cast<void**>(&m_raw_ptr);
    }
    
    out_ptr_t(const out_ptr_t&) = delete;
    out_ptr_t& operator=(const out_ptr_t&) = delete;
};

}
}
