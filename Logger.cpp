//
// Created by Dima Taras on 13.04.2023.
//
#include "Logger.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace log;

Logger::Logger() : out_{"text.txt"} {
    char * str;
// each message is prepended with the current time
    auto time = std::time(nullptr);
    auto t = strftime(str, 1000,"%t", std::localtime(&time));
    std::string temp(str);
    out_.operator<<(temp);
//// generate automatic file name with the current date/ time
//    std::ostringstream oss{};
//    auto time = std::time(nullptr);
//    oss << std::put_time(std::localtime(&time), "Log_%F_%H_%M_%S.txt");
//// open a new log file
//    if (out_.open(oss.str()); !out_.is_open()) {
//        std::cerr << "Logger::Logger: error opening log file " << oss.str() << '\n';
//    }
}
// notice: no `static` in the signature here!
// `static` is only placed in the declaration
Logger &Logger::get() {
    static Logger the_only_instance{};
    return the_only_instance;
}

void Logger::log(const std::string &msg) {
    if (out_.is_open()) {
        char * str;
// each message is prepended with the current time
        auto time = std::time(nullptr);
        auto t = strftime(str, 1000,"%t", std::localtime(&time));
        std::string temp(str);
        temp += msg;
        out_ << temp << "\n";
    } else {
        std::cerr << "Logger::log: log file not open\n";
    }
}