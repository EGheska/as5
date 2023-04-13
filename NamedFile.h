//
// Created by Dima Taras on 13.04.2023.
//

#ifndef ASS5_NAMEDFILE_H
#define ASS5_NAMEDFILE_H

#include <string>

namespace log {


    class NamedFile {
    public:
        // constructor, opens the file with the given name
        NamedFile(const std::string &file_name);

        // destructor
        ~NamedFile();

        // opens the file with the given name, closes the previous file if it was open
        void open(const std::string &file_name);

        // closes the file
        void close();

        // accessors
        bool is_open();

        bool error();

        bool eof();

        int lines();

        char size();

        std::string name();


        // writes the given value to the file if it is open
        // all those functions use std::fprintf or std::fputs
        NamedFile &operator<<(const std::string &value);

        NamedFile &operator<<(const char *value);

        NamedFile &operator<<(char value);

        NamedFile &operator<<(int number);

        NamedFile &operator<<(double number);

        // writes "true" or "false" to the file
        NamedFile &operator<<(bool value);

    private:
        std::string _filename;
        std::FILE *_file;
        bool _is_open;
        bool _error;
        bool _eof;
        bool _lines;
        bool _size;
    };
};

#endif //ASS5_NAMEDFILE_H
