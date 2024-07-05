#ifndef TASK_H
#define TASK_H

#include "logger.h"
#include <string>
typedef void(*func_ptr)() ;


class Task{
    protected:
    func_ptr exec;
    Logger* logger;
    int delay;
    long lastRun;
    public:
    Task(func_ptr exec, int delay);
    Task(int delay);
    Task();
    auto get_delay()->int;
    auto set_delay(int delay)->void;
    virtual void run();
    auto get_lastRun()->long;
    void set_lastRun(long lastRun);
    virtual std::string log();
};

#endif