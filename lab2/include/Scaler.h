// Header file for Matrix...
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <bits/stdc++.h>
using namespace std;

// Class to represent Matrix
class Matrix {
   
   public:
    // Constructor for Matrix
    Matrix(int rows, int columns);

    // Using Default Copy Constructor
    Matrix(const Matrix &m) = default;

    // Using Default Move Constructor
    Matrix(Matrix &&m) = default;

    // Destructor for Matrix
    ~Matrix() noexcept;

    // Functions to get number of rows or cols
    int getRows() const noexcept;
    int getCols() const noexcept;
    vector<vector<double>> getMatrix() const noexcept;

    // Overloaded operators
    // Default overloaded assignment operator
    Matrix &operator=(const Matrix &m) = default;
    Matrix &operator=(Matrix &&m) = default;

    // Operations: Scaler
    Matrix operator+(double x) const noexcept;
    Matrix operator-(double x) const noexcept;
    Matrix operator*(double x) const noexcept;
    Matrix operator/(double x) const;     // Division by Zero Exception
   
   private:

    int rows, cols;
    vector<vector<double>> matrix;
};

#endif  // _MATRIX_H_