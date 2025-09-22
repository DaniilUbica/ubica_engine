#pragma once

#include <chrono>

namespace game_engine {
namespace primitives {

namespace {

class ClockImpl {
public:
    static std::chrono::steady_clock::time_point now() {
        return std::chrono::steady_clock::now();
    }
};

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
        auto elapsed = getElapsedTime();
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
        if (isRunning()) {
            const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(ClockImpl::now() - m_refPoint);
            return static_cast<int64_t>(duration.count());
        }
        else {
            const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(m_stopPoint - m_refPoint);
            return static_cast<int64_t>(duration.count());
        }
    }

    [[nodiscard]] bool isRunning() const { return m_stopPoint == m_refPoint; };

private:
    std::chrono::steady_clock::time_point m_refPoint{ ClockImpl::now() };
    std::chrono::steady_clock::time_point m_stopPoint;
};

}
}
