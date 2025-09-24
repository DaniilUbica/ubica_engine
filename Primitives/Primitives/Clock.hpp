/*
 * This code was adapted from the SFML repository
 * https://github.com/SFML/SFML
 * Original file: SFML/include/SFML/System/Clock.hpp
 *
 * Modifications made:
 * - Changed time storage to microseconds (int64_t) instead of Time objects
 * - Removed SFML-specific dependencies
 */

#pragma once

#include <chrono>

namespace game_engine {
namespace primitives {

namespace {

using ClockImpl = std::conditional_t<std::chrono::high_resolution_clock::is_steady, std::chrono::high_resolution_clock, std::chrono::steady_clock>;

}

class Clock {
public:

    void start() {
        if (!isRunning()) {
            m_refPoint += ClockImpl::now() - m_stopPoint;
            m_stopPoint = {};
        }
    }

    void stop() {
        if (isRunning()) {
            m_stopPoint = ClockImpl::now();
        }
    }

    int64_t restart() {
        const auto elapsed = getElapsedTime();
        m_refPoint = ClockImpl::now();
        m_stopPoint = {};

        return elapsed;
    }

    int64_t reset() {
        auto elapsed = getElapsedTime();
        m_refPoint = ClockImpl::now();
        m_stopPoint = m_refPoint;

        return elapsed;
    }

    [[nodiscard]] int64_t getElapsedTime() const {
        if (isRunning())
            return std::chrono::duration_cast<std::chrono::microseconds>(ClockImpl::now() - m_refPoint).count();
        return std::chrono::duration_cast<std::chrono::microseconds>(m_stopPoint - m_refPoint).count();
    }

    [[nodiscard]] bool isRunning() const { return m_stopPoint == ClockImpl::time_point(); };

private:
    std::chrono::steady_clock::time_point m_refPoint{ ClockImpl::now() };
    std::chrono::steady_clock::time_point m_stopPoint;
};

}
}
