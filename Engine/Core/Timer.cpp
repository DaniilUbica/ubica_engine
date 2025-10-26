#include "Timer.h"

using namespace game_engine;

Timer::Timer(float time) : m_targetTime(time) {}

void Timer::Start() { 
    if (!m_isRunning && !m_isFinished) {
        Restart();
    }
}

void Timer::Pause() { 
    if (m_isRunning && !m_isPaused) {
        m_pauseStartTime = m_clock.getElapsedTime() / 1e+6;
        m_isPaused = true;
        m_isRunning = false;
     }
}

void Timer::Resume() { 
    if (m_isPaused) {
        m_elapsedTime += m_pauseStartTime;
        m_clock.restart();
        m_isPaused = false;
        m_isRunning = true;
    }
}

void Timer::Stop() { 
    if (m_isRunning) {
        if (!m_isPaused) {
            m_elapsedTime += m_clock.getElapsedTime() / 1e+6;
        }
        else {
            m_elapsedTime += m_pauseStartTime;
        }
        m_isRunning = false;
        m_isPaused = false;
    }
}

void Timer::Restart() { 
    m_clock.restart();
    m_elapsedTime = 0.0f;
    m_pauseStartTime = 0.0f;
    m_isRunning = true;
    m_isPaused = false;
    m_isFinished = false;
}

void Timer::Update() { 
    if (m_isRunning && !m_isPaused && !m_isFinished) {
        if (elapsedTime() >= m_targetTime) {
            m_isFinished = true;
            m_isRunning = false;
        }
    }
}

void Timer::setTime(float time) {
    m_targetTime = time;
    reset();
}

float Timer::remainingTime() const { 
    if (m_isFinished) {
        return 0.0f;
    }

    float remaining = m_targetTime - elapsedTime();
    return remaining > 0 ? remaining : 0.0f;
}

float Timer::elapsedTime() const { 
    if (!m_isRunning || m_isFinished) {
        return m_elapsedTime;
    }

    if (m_isPaused) {
        return m_elapsedTime;
    }

    return m_elapsedTime + m_clock.getElapsedTime() / 1e+6;
}

void Timer::reset() {
    m_clock.restart();
    m_elapsedTime = 0.0f;
    m_pauseStartTime = 0.0f;
    m_isRunning = false;
    m_isPaused = false;
    m_isFinished = false;
}
