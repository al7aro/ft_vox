#pragma once

#include <chrono>

namespace ft {

    class Timer
    {
    private:
        std::chrono::steady_clock::time_point _start;
    public:
        Timer()
        {
            _start = std::chrono::steady_clock::now();
        }

        void Restart()
        {
            _start = std::chrono::steady_clock::now();
        }

        double EllapsedMiliseconds() const
        {
            std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
            std::chrono::steady_clock::duration ellapsed = now - _start;
            return (std::chrono::duration_cast<std::chrono::milliseconds>(ellapsed).count());
        }

        double EllapsedSeconds() const
        {
            return (EllapsedMiliseconds() / 1000.0);
        }

    };

}