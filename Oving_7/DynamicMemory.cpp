#include <cassert>
#include <iostream>
#include <iomanip>

#include "DynamicMemory.h"


// BEGIN: 1a
void fillInFibonacciNumbers(int* result, int length)
{
    result[0] = 0;
    result[1] = 1;
    for (int i=2; i<length;i++)
    {
        result[i] = result[i-1] + result[i-2];
    }
}
// END: 1a

// BEGIN: 1b
void printArray(int* array, int length)
{
    for (int i=0;i<length;i++)
    {
        std::cout << array[i] << "  ";
    }
    std::cout << std::endl;
}
// END: 1b

// BEGIN: 1c
void createFibonacci()
{
// 1. Spør brukeren hvor mange tall som skal genereres
    int num;
    std::cout << "How many Fibonacci numbers? ";
    std::cin >> num;
// 2. Alloker minne til en tabell som er stor nok til tallrekka
    int* tabell = new int[num] {};

// 3. Fylle tabellen med fillInFibonacciNumbers()
    fillInFibonacciNumbers(tabell,num);
// 4. Skriv ut resultatet til skjerm med printArray()
    printArray(tabell,num);
// 5. Frigjør minnet du har reservert
    delete[] tabell;
    tabell = nullptr;
}
// END: 1c
