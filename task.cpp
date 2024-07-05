#include "task.h"
#include "logger.h"

auto Task::run()->void{
    (*exec)();
}
auto Task::set_delay(int delay)->void{
    this->delay = delay;
}
auto Task::get_delay()->int{
    return delay;
}
Task::Task(func_ptr exec, int delay): exec(exec), delay(delay) {
    logger = new Logger("./game.log", "tasks");
}
Task::Task(int delay): delay(delay) { 
    logger = new Logger("./game.log", "tasks");
}
Task::Task() { 
    logger = new Logger("./game.log", "tasks");
}
auto Task::get_lastRun()->long{
    return  lastRun;
}
void Task::set_lastRun(long lr){
    lastRun = lr;
}
std::string Task::log(){
    return"";
}
