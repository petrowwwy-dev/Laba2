#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

class Logger {
public:
    static void log(const std::string& action) {
        std::ofstream file("history.txt", std::ios::app); 
        if (file.is_open()) {
            
            auto now = std::chrono::system_clock::now();
            std::time_t now_c = std::chrono::system_clock::to_time_t(now);
            char timeBuf[26];
            ctime_s(timeBuf, sizeof(timeBuf), &now_c);
            std::string timeStr(timeBuf);
            timeStr.pop_back(); 

            file << "[" << timeStr << "] " << action << "\n";
            file.close();
        }
    }
};
