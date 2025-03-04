#ifndef SAVER_H
#define SAVER_H

#include <fstream>
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <filesystem>

class Saver {
public:
    void saveData(const std::string& sensorName, bool check);
    
private:
    std::string getLogFilePath(const std::string& sensorName);
};

#endif // SAVER_H
