//
// Created by Dima Taras on 13.04.2023.
//

#ifndef ASS5_LOGGER_H
#define ASS5_LOGGER_H

#include "NamedFile.h"

namespace log {

    class Logger {
    public:
// gets the singleton instance of Logger
        Logger &get();

        void log(const std::string &msg);

    private:
// private, default constructor
        Logger();

// logging file
        NamedFile out_;
    };
}

#endif //ASS5_LOGGER_H
