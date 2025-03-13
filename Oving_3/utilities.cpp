#include "utilities.h"
#include <random>

// BEGIN: 5a
int randomWithLimits(int nedreLim, int ovreLim) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(nedreLim,ovreLim);   

    return distribution(generator);
}
// END: 5a