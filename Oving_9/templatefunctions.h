#pragma once
#include <random>
#include <iostream>
#include <string>
#include <vector>

// BEGIN 4a
template<typename T>
T maximum(T a, T b) {
    if (a>b) {
        return a;
    }
    return b;
}
// END 4a

// BEGIN 4b
template<typename type>
void shuffle(std::vector<type>& vect) {
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<> dis(0,vect.size()-1);
    for (int i = 0;i<100*vect.size();++i) {
        size_t a = dis(gen);
        size_t b = dis(gen);
        std::swap(vect[a],vect[b]);
    }
}
// END 4b

void testTemplateFunctions();