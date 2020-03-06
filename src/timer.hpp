#pragma once

#include <chrono>
#include <fstream>
#include <iostream>
#include <future>
#include <string>
#include <thread>

namespace timer
{
template <typename T>
inline void time(std::string file_name, T function)
{
    static std::mutex mutex;
    static std::size_t counter = 0;

    const auto start = std::chrono::high_resolution_clock::now();
    function();
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::nanoseconds duration = end - start;

    std::async(std::launch::async, [&, duration, end, start] {
        std::unique_lock<std::mutex> write_lock{mutex};

        std::ofstream f;
        f.open(file_name, std::ios_base::app | std::ios_base::ate);
        f << std::to_string(counter) + "," + std::to_string(end.time_since_epoch().count()) + "," + std::to_string(start.time_since_epoch().count()) + "," + std::to_string(duration.count()) + "\n";
        f.close();
        // std::cout << "[" << file_name << "]" << std::to_string(counter) + "," + std::to_string(end.time_since_epoch().count()) + "," + std::to_string(start.time_since_epoch().count()) + "," + std::to_string(duration.count()) + "\n";

        counter++;
    });
}
} // namespace timer
