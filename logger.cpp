#include "logger.h"
#include <fstream>


Logger::Logger(std::string fp):filePath(fp){}
Logger::Logger(std::string fp, std::string name){
    filePath = fp;
    this->name = name;
}

void Logger::log(std::string str){
    std::ofstream f;
    f.open(filePath, std::ios::app);
    f << name << " - " << str << std::endl;
    f.close();
}