#pragma once
#include <iostream>
#include <exception>

// BEGIN 5a
template<typename Type, int Size>
// END 5a
class MyArray {
private:
    // BEGIN 5b
    Type elements[Size];
    // END 5b
public:
    // BEGIN 5c
    int getSize() const {return Size;}
    Type& at(int index) {
        if (index < 0 || index >= Size) {
            throw std::out_of_range("Index out of range: " + std::to_string(index));
        }
        return elements[index];
    }
    void fill(Type n) {for (int i=0;i<Size;++i) {elements[i] = n;}}
    // END 5c
};

// BEGIN 5d
void testMyArray();
// END 5d