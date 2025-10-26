#include "ThreadedTimer.h"

using namespace game_engine;

void ThreadedTimer::runTimer() {
    std::unique_lock<std::mutex> lock(m_mutex);

    auto startTime = std::chrono::steady_clock::now();
    auto targetDuration = std::chrono::milliseconds(static_cast<int>(m_remainingTime * 1000));

    while (m_remainingTime > 0 && !m_stop) {
        if (m_cv.wait_for(lock, targetDuration, [this]() {
            return m_stop.load() || m_paused.load();
        })) {
            if (m_paused) {
                auto currentTime = std::chrono::steady_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime);
                m_remainingTime = m_time - (elapsed.count() / 1000.0f);

                m_cv.wait(lock, [this]() {
                    return !m_paused.load() || m_stop.load();
                });

                if (!m_stop && !m_paused) {
                    startTime = std::chrono::steady_clock::now();
                    targetDuration = std::chrono::milliseconds(static_cast<int>(m_remainingTime * 1000));
                }
            }

            if (m_stop) {
                break;
            }
        } else {
            m_remainingTime = 0;
            break;
        }
    }

    if (m_remainingTime <= 0 && !m_stop) {
        m_running = false;
    }
}

ThreadedTimer::ThreadedTimer(float time) {
	m_time = time;
}

ThreadedTimer::~ThreadedTimer() {
    m_stop = true;
    m_cv.notify_all();
    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void ThreadedTimer::Start() {
    if (m_running) {
        return;
    }

    m_running = true;
    m_stop = false;
    m_paused = false;
    m_remainingTime = m_time;

    if (m_thread.joinable()) {
        m_thread.join();
    }

    m_thread = std::thread([this]() {
        runTimer();
    });
}

void ThreadedTimer::Stop() {
    m_stop = true;
    m_running = false;
    m_paused = false;
    m_cv.notify_all();
}

void ThreadedTimer::Pause() {
    if (!m_running || m_paused) {
        return;
    }

    std::unique_lock<std::mutex> lock(m_mutex);
    m_paused = true;
    m_pauseTime = std::chrono::steady_clock::now();
}

void ThreadedTimer::Resume() {
    if (!m_running || !m_paused) {
        return;
    }

    std::unique_lock<std::mutex> lock(m_mutex);

    auto now = std::chrono::steady_clock::now();
    auto pausedDuration = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_pauseTime);

    m_remainingTime -= pausedDuration.count() / 1000.0f;

    m_paused = false;
    m_cv.notify_all();
}

void ThreadedTimer::setTime(float time) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_time = time;
    if (m_running && !m_paused) {
        m_remainingTime = time;
    }
}

bool ThreadedTimer::isRunning() const {
    return m_running && !m_paused;
}

bool ThreadedTimer::isPaused() const {
    return m_paused;
}

float ThreadedTimer::getRemainingTime() const {
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_remainingTime;
}
