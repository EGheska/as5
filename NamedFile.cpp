//
// Created by Dima Taras on 13.04.2023.
//

#include "NamedFile.h"

using namespace log;

NamedFile::NamedFile(const std::string &file_name) : _file{}, _filename{file_name} {
    _file = std::fopen(file_name.c_str(), "w");
}

NamedFile::~NamedFile() {
    fclose(_file);
    //  delete[] _file;
}

void NamedFile::open(const std::string &file_name) {
    if (_file != nullptr) {
        fclose(_file);
        _file = std::fopen(file_name.c_str(), "r");
    } else {
        _file = std::fopen(file_name.c_str(), "r");
    }
}

void NamedFile::close() {
    fclose(_file);
}

NamedFile &NamedFile::operator<<(const std::string &value) {
    if (_file != nullptr) {
        std::fputs(value.c_str(), _file);
    }
    return *this;
}

NamedFile &NamedFile::operator<<(const char *value) {
    if (_file != nullptr) {
        std::fputs(value, _file);
    }
    return *this;
}

NamedFile &NamedFile::operator<<(char value) {
    if (_file != nullptr) {
        std::fputc(value, _file);
    }
    return *this;
}

NamedFile &NamedFile::operator<<(int number) {
    if (_file != nullptr) {
        std::fprintf(_file, "%d", number);
    }
    return *this;
}

NamedFile &NamedFile::operator<<(double number) {
    if (_file != nullptr) {
        std::fprintf(_file, "%.1f", number);
    }
    return *this;
}

NamedFile &NamedFile::operator<<(bool value) {
    if (_file != nullptr) {
        std::fprintf(_file, "%d", value);
    }
    return *this;
}

bool NamedFile::is_open() {
    if (_file != nullptr) {
        _is_open = true;
        return true;
    } else {
        return false;
    }
}

bool NamedFile::error() {
    if (std::ferror(_file)) {
        return true;
    }
    return false;
}

bool NamedFile::eof() {
    if (std::feof(_file)) {
        return true;
    }
    return false;
}

int NamedFile::lines() {
    int ch;
    int number_of_lines = 0;
    while (eof() != (ch = getc(_file))) {
        if ('\n' == ch) {
            number_of_lines++;
        }
    }
    return number_of_lines;
}

char NamedFile::size() {
    return std::fprintf(_file, "n");
}

std::string NamedFile::name() {
    return _filename;
}
