#pragma once
#include <utility>

class Dummy {
public:
    int *num;

    Dummy() {
        num = new int{0};
    }
    // BEGIN: 3c
    Dummy(const Dummy& rhs)
    {
        //this->num = new int{*rhs.num};
        this -> num = new int;
        *num = *rhs.num;
    }
    // END: 3c

	// Copy-Swap: Tar inn rhs som kopi, bytter medlemsvariable
    // BEGIN: 3d
	Dummy& operator=(Dummy rhs)
    {
        std::swap(num,rhs.num);
        return *this;
    }
    // END: 3d
    
    ~Dummy() {
        delete num;
    }
};

void dummyTest();
