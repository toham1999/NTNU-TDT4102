#pragma once
#include <iostream>
#include <utility>


class Matrix {
private:
// BEGIN: 2a
    double** matrix;
    int rows = 1;
    int columns = 1;
// END: 2a
public:
    // BEGIN: 2b
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();
    // END: 2b
    
    // BEGIN: 2c
    double get(int row, int col) const;
    void set(int row, int col, double value);
    // END: 2c

    // Her kan du gjøre 2d (frivillig):
    double* operator[](int placement) const;

    // BEGIN: 2e
    int getRows() const { return rows; }
    int getColumns() const { return columns; }
    // END: 2e

    
    // BEGIN: 4a
    Matrix(const Matrix& rhs);
    // END: 4a

    // BEGIN: 4b
    Matrix& operator=(Matrix rhs);
    // END: 4b


    // BEGIN: 5a
    Matrix& operator+=(const Matrix& rhs);
    // END: 5a

    // BEGIN: 5b
    Matrix operator+(const Matrix& rhs) const;
    // END: 5b

    // Her kan du gjøre 5d (frivillig):
    
};


// BEGIN: 2f
std::ostream& operator<<(std::ostream& os, const Matrix& rhs);
// END: 2f

void testMatrix();