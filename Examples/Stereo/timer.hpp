#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <utility>

struct timer
{
    timer(std::string name) : name{std::move(name)}, start_time{std::chrono::high_resolution_clock::now()}
    {
    }

    ~timer()
    {
        const std::chrono::duration<float> interval = std::chrono::high_resolution_clock::now() - start_time;
        std::cout << "[TIMER] " << name << ": " << interval.count() << std::endl;
    }

private:
    std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};
