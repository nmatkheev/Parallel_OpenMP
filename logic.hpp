/* --------------------------------------------------------------- */
//                  You do not need to touch this
/* --------------------------------------------------------------- */

#include "profiled.hpp"

#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using Numbers = std::vector<double>;

// Generates array like [0,1,2,3,4,...]
Numbers get_array(int sz) {
    Numbers array(sz);
    std::iota(array.begin(), array.end(), 0.0);
    return std::move(array);
}

// Assumes array is generated with fill_array()
bool check_avg(const Numbers& array, double avg) {
    double expected = (double)(array.front() + array.back()) / 2;
    if( (expected - avg) / std::max(expected, avg) > 0.01 ) {
        std::cout << "Average counted wrong! Expected: " << expected << ", found: " << avg << std::endl;
    }
    return expected == avg;
}

/* --------------------------------------------------------------- */
//                       INSERT YOUR CODE HERE
/* --------------------------------------------------------------- */

// Helper to doubling algorithm, maybe you will not need it
// in concurrent-style program
Numbers doubling_step(Numbers array) {
    double halfsize = ceil(double(array.size()) / 2);
    
    for(size_t i = 0; i < halfsize; ++i) {
        array[i] = (array[i] + array[i + halfsize]) / 2;
    }
    array.resize(halfsize);
    return std::move(array);
}

// Calculates array average in non-parallel style
double get_avg(Numbers array) {
    while( array.size() > 1 ) {
        array = doubling_step(std::move(array));
    }
    return array.at(0);
}

