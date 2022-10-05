// CPP File for Matrix
#include "../include/Scaler.h"
#include "../include/constants.h"
#include "../include/exceptions.h"
#include "../include/logger.h"
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

// Constructor
Matrix::Matrix(int rows, int cols) 
    : rows{rows}, cols{cols} {
    if (rows <= 0 || cols <= 0) 
    {
        InvalidDimentionInput A;
        Log::ThrowError(A.what());
    }

    matrix.assign(rows, vector<double>(cols, 0));
}

int Matrix::getRows() const noexcept {
    return this->rows;
}

int Matrix::getCols() const noexcept {
    return this->cols;
}

vector<vector<double>> Matrix::getMatrix() const noexcept {
    return this->matrix;
}

// Destructor
Matrix ::~Matrix() noexcept {
}

// Operations: Scaler
Matrix Matrix::operator+(double x) const noexcept 
{
    Matrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.matrix[i][j] = this->matrix[i][j] + x;
        }
    }

    return result;
}

Matrix Matrix::operator-(double x) const noexcept 
{
    Matrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.matrix[i][j] = this->matrix[i][j] - x;
        }
    }

    return result;
}

Matrix Matrix::operator*(double x) const noexcept 
{
    Matrix result(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.matrix[i][j] = this->matrix[i][j] * x;
        }
    }

    return result;
}

Matrix Matrix::operator/(double x) const 
{
    if (x == 0) 
    {
        DividingByZeroException A;
        Log::ThrowError(A.what());
    }

    Matrix result(this->rows, this->cols);
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->cols; j++) 
        {
            result.matrix[i][j] = this->matrix[i][j] / x;
        }
    }

    return result;
}

