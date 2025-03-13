#include "templatefunctions.h"

void testTemplateFunctions(){
    // Her kan du teste templatefunksjonene dine
    /*
    int a = 1;
    int b = 2;
    int c = maximum<int>(a, b);
    std::cout << c << std::endl;
    double d = 2.4;
    double e = 3.2;
    double f = maximum<double>(d,e);
    std::cout << f << std::endl;
    */
    std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
    shuffle(a); // Resultat, rekkefølgen i a er endret.
    std::vector<double> b{1.2, 2.2, 3.2, 4.2};
    shuffle(b); // Resultat, rekkefølgen i b er endret.
    std::vector<std::string> c{"one", "two", "three", "four"};
    shuffle(c); // Resultat, rekkefølgen i c er endret.
}
