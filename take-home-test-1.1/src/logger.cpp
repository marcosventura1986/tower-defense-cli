//Copyright 2K Games, Engineering Graduate Program. All rights reserved. DO NOT redistribute.

#include "logger.h"

// renders a single instance of the logger on the terminal
Logger &Logger::GetInstance() {
    static Logger instance;  // Static instance
    return instance;
}

// constructor method
Logger::Logger() {
    logFile.open("game.log", std::ios::out | std::ios::app);
}

// destructor method
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// sends a message to the logger
void Logger::Log(const std::string &message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}

// flushes the log
void Logger::Flush() {
    if (logFile.is_open()) {
        logFile.flush();
    }
}
