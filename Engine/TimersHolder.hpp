#pragma once

#include "Core/Timer.h"

#include <vector>

namespace game_engine {

namespace {
    using timer_t = std::shared_ptr<Timer>;
    using weak_timer_t = std::weak_ptr<Timer>;
}

class TimersHolder {
public:
    static timer_t createTimer(unsigned int duration) {
        const auto timer = std::make_shared<Timer>(duration);
        m_timers.push_back(timer);
        return timer;
    }

    static void deleteExpiredTimers() {
        m_timers.erase(std::remove_if(m_timers.begin(), m_timers.end(), [](const auto& timer) {
            return timer.expired();
        }), m_timers.end());
    }

    static void pauseAllTimers() {
        for (auto& timer : m_timers) {
            if (auto sp = timer.lock()) {
                sp->Pause();
            }
        }
    }

    static void resumeAllTimers() {
        for (auto& timer : m_timers) {
            if (auto sp = timer.lock(); sp && sp->isPaused()) {
                sp->Resume();
            }
        }
    }

    static void stopAllTimers() {
        for (auto& timer : m_timers) {
            if (auto sp = timer.lock()) {
                sp->Stop();
            }
        }
    }

private:
    inline static std::vector<weak_timer_t> m_timers;
};

}
