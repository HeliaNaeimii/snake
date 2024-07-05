#ifndef LOGGER_H
#define LOGGER_H

#include <string>
class Logger{
    private:
    std::string filePath;
    std::string name = "";
    public:
    Logger(std::string fp);
    Logger(std::string fp, std::string name);
    void log(std::string str);

};

#endif