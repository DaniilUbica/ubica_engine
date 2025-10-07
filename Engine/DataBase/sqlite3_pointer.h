#pragma once

#include <memory>

struct sqlite3;
struct sqlite3_stmt;

namespace game_engine {
namespace database {

int sqlite3_close(sqlite3*);
int sqlite3_finalize(sqlite3_stmt*);

template<class T>
constexpr inline void(*release)(T*);

template<>
constexpr inline auto release<sqlite3> = sqlite3_close;
template<>
constexpr inline auto release<sqlite3_stmt> = sqlite3_finalize;

template<class T> struct deleter {
    void operator()(T target) const {
        return release<T>(target);
    }
};

template<typename T>
using sqlite3_pointer = std::unique_ptr<T, deleter<T>>;

}
}
