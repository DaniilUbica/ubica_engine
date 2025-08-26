#pragma once

#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace game_engine {

/**
 * @class Timer
 * @brief A thread-safe timer class that runs in a separate thread.
 *
 * The Timer class provides a countdown timer functionality that operates
 * asynchronously using a dedicated thread. It supports starting the timer,
 * checking if it's running, and safely stopping it during destruction.
 * The class uses atomic variables and synchronization primitives to ensure
 * thread safety.
 */
class Timer {
private:
    float m_time;
    std::atomic<bool> m_running{false};
    std::atomic<bool> m_stop{false};
    std::thread m_thread;
    std::condition_variable m_cv;
    std::mutex m_mutex;

public:
    Timer(float time);
    ~Timer();

    /**
     * @brief Starts the timer asynchronously.
     *
     * Launches a separate thread that will count down from the specified time.
     * The timer can be checked for completion using isRunning().
     */
    void Start();

    /**
     * @brief Sets a new duration for the timer.
     * @param time The new duration
     *
     * @note This should typically be called before starting the timer.
     * Changing the time while the timer is running may have undefined behavior.
     */
    void setTime(float time);

    /**
     * @brief Checks if the timer is currently running.
     * @return bool True if the timer is running, false otherwise
     */
    bool isRunning();
};

}
