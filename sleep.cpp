#include "sleep.h"
#include <thread>
#include <chrono>

void sleep(int milisecounds) { 
    std::this_thread::sleep_for(std::chrono::milliseconds(milisecounds));
}