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
        std::erase_if(m_timers, [](const weak_timer_t& timer) {
            return timer.expired();
        });
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

private:
    inline static std::vector<weak_timer_t> m_timers;
};

}
