//Copyright 2K Games, Engineering Graduate Program. All rights reserved. DO NOT redistribute.

#pragma once

#include <string>
#include <fstream>

class Logger {
public:
    static Logger &GetInstance();  // Singleton instance accessor

    void Log(const std::string &message);
    void Flush();

private:
    Logger();  // Private constructor for Singleton
    ~Logger();
    Logger(const Logger &) = delete;  // Prevent copy construction
    Logger &operator=(const Logger &) = delete;  // Prevent assignment

    std::ofstream logFile;
};
