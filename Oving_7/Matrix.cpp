#include "Matrix.h"
#include <cassert>
#include <iomanip>
#include <algorithm>

// BEGIN: 2b
Matrix::Matrix(int nRows, int nColumns) : rows(nRows), columns(nColumns)
{
    assert(nRows > 0 && nColumns > 0 && "Matrix dimensions must be positive!");

    matrix = new double*[nRows] {};
    for (int i=0;i<nRows;i++)
    {
        matrix[i] = new double[nColumns] {};
    }
}

Matrix::Matrix(int nRows): Matrix(nRows, nRows) 
{
    for (int j=0;j<nRows;j++) // Add the identity matrix ones
    {
        matrix[j][j] = 1;
    }
}

Matrix::~Matrix()
{
    for (int i=0;i<rows;i++)
    {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}
// END: 2b

// BEGIN: 2c
double Matrix::get(int row, int col) const
{
    return matrix[row][col];
}
void Matrix::set(int row, int col, double value)
{
    matrix[row][col] = value;
}
// END: 2c

// Her kan du gjøre 2d (frivillig):
double* Matrix::operator[](int placement) const
{
    return matrix[placement];
}

// BEGIN: 2f
#include <iomanip> // cant use this in INgious if not inside here
std::ostream& operator<<(std::ostream& os, const Matrix& rhs)
{
    int nrOfRows = rhs.getRows(); 
    int nrOfColumns = rhs.getColumns();
    for (int j=0;j<nrOfRows;j++)
    {
        for (int i=0;i<nrOfColumns;i++)
        {
            os << std::setw(5) << rhs.get(j,i);
        }
        os << std::endl;
    }
    return os;
}
// END: 2f


// BEGIN: 4a
#include <algorithm> // cant use this in INgious if not inside here
Matrix::Matrix(const Matrix& rhs) : rows(rhs.rows), columns(rhs.columns)
{
    matrix = new double*[rows] {};
    for (int i=0;i<rows;i++)
    {
        matrix[i] = new double[columns] {};
        std::copy(rhs.matrix[i],rhs.matrix[i] + columns, matrix[i]);
    }
}
// END: 4a

// BEGIN: 4b
Matrix& Matrix::operator=(Matrix rhs)
{
    std::swap(matrix, rhs.matrix);
    std::swap(rows, rhs.rows);
    std::swap(columns, rhs.columns);
    return *this;
}
// END: 4b


// BEGIN: 5a
Matrix& Matrix::operator+=(const Matrix& rhs)
{
    assert(rows == rhs.rows && columns == rhs.columns && "Matrix dimensions must be the same!");
    for (int j=0;j<rows;j++)
    {
        for (int i=0;i<columns;i++)
        {
            matrix[j][i] = matrix[j][i] + rhs.matrix[j][i];
        }
    }
    return *this;
}
// END: 5a

// BEGIN: 5b
Matrix Matrix::operator+(const Matrix& rhs) const
{
    assert(rows == rhs.rows && columns == rhs.columns && "Matrix dimensions must be the same!");
    Matrix result{*this};
    result += rhs;
    return result;
}
// END: 5b


void testMatrix() {
    // Her kan du teste løsningen din (oppgave 5c):
    int rowss = 2;
    int columnss = 2;

    std::cout << "Matrix A:" << std::endl;
    Matrix A(rowss,columnss);
    A.set(0,0,1);
    A.set(0,1,2);
    A.set(1,0,3);
    A.set(1,1,4);
	std::cout << A << std::endl;

    std::cout << "Matrix B:" << std::endl;
    Matrix B(rowss,columnss);
    B.set(0,0,4);
    B.set(0,1,3);
    B.set(1,0,2);
    B.set(1,1,1);
	std::cout << B << std::endl;

    std::cout << "Matrix C:" << std::endl;
    Matrix C(rowss,columnss);
    C.set(0,0,1);
    C.set(0,1,3);
    C.set(1,0,1.5);
    C.set(1,1,2);
	std::cout << C << std::endl;

    A += B + C;
    std::cout << "A += B + C:" << std::endl;
    std::cout << A << std::endl;
}

// Her kan du gjøre 5d (frivillig):