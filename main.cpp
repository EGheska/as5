#include <iostream>
#include "NamedFile.h"
#include "Logger.h"

int main() {

    log::NamedFile out{"text.txt"};
    auto& result1 = out.operator<<("Hello, ");
    auto& result2 = result1.operator<<(42);
    auto& result3 = result2.operator<<(" worlds!");
    auto& result4 = result3.operator<<('\n');
    auto& result5 = result4.operator<<("Hello, ");
    auto& result6 = result5.operator<<(4.2);
    auto& result7 = result6.operator<<(" worlds!");
    auto& result8 = result7.operator<<('\n');
    auto& result9 = result8.operator<<(true);
// log::Logger







    //    NamedFile file{"test.txt"};
//    file.open("test.txt");
//    file.is_open();
//    file.size();
//    file.operator<<("true");
//    file.operator<<('c');
//    file.operator<<(4);
//    file.operator<<(1.5);
//    file.operator<<("Dima");
    return 0;
}
