/* --------------------------------------------------------------- */
//                  You do not need to touch this
/* --------------------------------------------------------------- */

#include "logic.hpp"

int main(int argc, char** argv) {
    if( argc < 3 ) {
        std::cout << "Usage: " << argv[0] << " <retries> <array_size>" << std::endl;
        return 0;
    }
    const int RETRIES = atoi(argv[1]);
    const int ARR_SIZE = atoi(argv[2]);
    if( RETRIES == 0 || ARR_SIZE == 0 ) {
        std::cout << "Both retries and array_size should be valid positive numbers" << std::endl;
        return 0;
    }

    Profiled p;

    for( int i = 0 ; i < RETRIES; ++i ) {
        Numbers array = get_array(ARR_SIZE);
        double avg = get_avg(array);
        if( !check_avg(array, avg) ) {
            break;
        }
    }
}
