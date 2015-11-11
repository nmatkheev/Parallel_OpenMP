/* --------------------------------------------------------------- */
//                  You do not need to touch this
/* --------------------------------------------------------------- */

#include "rss.hpp"

#include <map>
#include <chrono>
#include <iostream>

std::string pretty_size(unsigned int size) {
    auto init_size = size;
    unsigned int order = 0;
    while( size >= 20000 ) {
        ++order;
        size /= 1024;
    }
    std::map<int, std::string> orders = {{0, ""}, {1, "K"}, {2, "M"}, {3, "G"}};
    auto o = orders.find(order);
    if( o == orders.end() ) {
        ;
    }
    auto c = o == orders.end() ? std::string() : orders.at(order);
    return std::to_string(size) + c;
}

using namespace std::chrono;

struct Profiled {
    Profiled() : begin(system_clock::now()) {}
    ~Profiled() {

        auto elapsed_ms = duration_cast<milliseconds>(system_clock::now() - begin);
        auto ram_used = getPeakRSS();

        std::cout << "Time elapsed:\t" << elapsed_ms.count() << "ms" << std::endl;
        std::cout << "RSS:\t\t" << pretty_size(ram_used) << std::endl;
    }

    system_clock::time_point begin;
};
