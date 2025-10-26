#pragma once

#include "Primitives/Clock.hpp"

namespace game_engine {

class Timer {
public:
    Timer(float time);

    void Start();
    void Pause();
    void Resume();
    void Stop();
    void Restart();

    void Update();

    void setTime(float time);

    float remainingTime() const;
    float elapsedTime() const;

    bool running() const { return m_isRunning && !m_isPaused && !m_isFinished; };
    bool paused() const { return m_isPaused; };
    bool finished() const { return m_isFinished; };


private:
    void reset();

    primitives::Clock m_clock;
    float m_elapsedTime = 0;
    float m_pauseStartTime = 0;
    float m_targetTime = 0;
    bool m_isRunning = false;
    bool m_isPaused = false;
    bool m_isFinished = false;
};

}
