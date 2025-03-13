#include "MyArray.h"

// BEGIN 5d
void testMyArray() {
    try {
        // Create a MyArray object for integers with size 5
        MyArray<int, 5> intArray;

        // Fill the array with the value 10
        intArray.fill(10);

        // Fill elemetn at index 2 with the value 20
        intArray.at(2) = 20;

        // Print the size of the array
        std::cout << "Array size: " << intArray.getSize() << std::endl;

        // Access elements inside the bounds and print them
        for (int i = 0; i < intArray.getSize(); ++i) {
            std::cout << "Element at index " << i << ": " << intArray.at(i) << std::endl;
        }

        // Try to access an element outside the bounds (this should throw an exception)
        std::cout << "Accessing element at index 5 (out of bounds): " << intArray.at(5) << std::endl;

    } 
    catch (const std::out_of_range& e) {
        // Handle out_of_range exception and print an error message
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}
// END 5d