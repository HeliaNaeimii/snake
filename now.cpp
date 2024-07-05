#include "now.h"
#include <chrono>

long Now() {
    auto chrono_now = std::chrono::system_clock::now();
    auto duration = chrono_now.time_since_epoch();
    auto milis_now = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return milis_now;
}