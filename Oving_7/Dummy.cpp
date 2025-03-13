#include "Dummy.h"
#include <iostream>


void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;

    std::cout << "a: " << *a.num << " " << a.num << '\n';
    std::cout << "b: " << *b.num << " " << b.num << '\n';
    std::cout << "c: " << *c.num << " " << c.num << '\n';
    
    *b.num = 3;
    *c.num = 5;

    std::cout << "a: " << *a.num << " " << a.num << '\n';
    std::cout << "b: " << *b.num << " " << b.num << '\n';
    std::cout << "c: " << *c.num << " " << c.num << '\n';
}
