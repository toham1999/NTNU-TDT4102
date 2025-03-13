#include "Stopwatch.h"
#include "optimizeVector.h"
#include <vector>
#include <iostream>


// BEGIN 2a
void testVector() {
    std::vector<int> vect;
    vect.reserve(20);
    for (int i = 0;i<20;++i) {
        vect.emplace_back(i);
        std::cout << "Size: " << vect.size() 
        << ", Capacity: " << vect.capacity() << std::endl;
    }
}
// END 2a


void optimizeVector(){
    // BEGIN 2d
    Stopwatch stopwatch;
    stopwatch.start();
    std::vector<int> millionList;
    for (int i = 0;i<1000000;++i) {
        millionList.push_back(i);
    }
    std::cout << "Oppgave 2d: " << stopwatch.stop() << " s" << std::endl;
    // END 2d

    // BEGIN 2e
    Stopwatch stopwatch2;
    stopwatch2.start();
    std::vector<int> millionList2;
    /*
    millionList2.reserve(itterator);
    for (int i = 0;i<itterator;++i) {
        millionList2.push_back(i);
    }
    */
    millionList2.resize(1000000);
    for (int i = 0;i<1000000;++i) {
        millionList2[i];
    }
    std::cout << "Oppgave 2e: " << stopwatch2.stop() << " s" << std::endl;
    // END 2e   
}