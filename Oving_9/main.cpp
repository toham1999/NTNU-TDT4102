#include "Stopwatch.h"
#include "measurePerformance.h"
#include "optimizeVector.h"
#include "optimizationTask.h"
#include "templatefunctions.h"
#include "MyArray.h"



int main() {
    // Oppgave 1
    //std::cout << "Unique ptr avg time: " << measurePerformanceUnique() << " ms" << std::endl;
    //std::cout << "Shared ptr avg time: " << measurePerformanceShared() << " ms" << std::endl;
    //std::cout << "Stack alloc avg time: " << measurePerformanceStack() << " ms" << std::endl;
    //std::cout << "Heap alloc avg time: " << measurePerformanceHeap() << " ms" << std::endl;

    // Oppgave 2
    //testVector();
    //optimizeVector();

    // Oppgave 3 
    // Before:                          Time taken: 6.55738seconds
    // Make setDiagonalValue() simple : Time taken: 5.33939seconds
    // Static_cast on sumMatrix()     : Time taken: 4.21714seconds
    // 3c, release mode               : Time taken: 2.63114seconds
    //optimizationTask();

    // Oppgave 4
    //testTemplateFunctions();
    
    // Oppgave 5
    testMyArray();
    return 0;
}