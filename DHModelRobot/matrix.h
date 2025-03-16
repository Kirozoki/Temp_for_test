#ifndef MATRIX_H
#define MATRIX_H
#pragma once
#include <iostream>
#include <vector>

class Matrix {

private:
    std::vector<double> data;
    int rows_;
    int columns_;

public:
    Matrix(int n, int m);

    Matrix(Matrix&& other) : data(std::move(other.data)), rows_(other.rows_),
        columns_(other.columns_) {
    }

    Matrix(const Matrix& other) : data(other.data), rows_(other.rows_),
        columns_(other.columns_) {}

    Matrix& operator=(Matrix&& other);

    Matrix& operator=(const Matrix& other);

    Matrix& operator*=(Matrix other);

    Matrix& operator+=(Matrix other);

    ~Matrix() {}

    void set_value(int row, int col, double value);

    static void multiply(Matrix* x, Matrix* y, Matrix* results) {

        if ((!x) || (!y) || (!results)) {
            std::cerr << "Error: one of matrices is not created"
                      << std::endl;
        }

        if ((x->columns_ != y->rows_) || (results->columns_ != y->columns_)
            || (results->rows_ != x->rows_)) {
            std::cerr << "Error : Ivalid dimensions of matrices for multiplication"
                      << std::endl;
        }

        int result_array_size = results->rows_ * results->columns_;

        for (int i = 0; i < result_array_size; ++i) {

            for(int j = 0; j < x->columns_; ++j) {
                results->data[i] += x->data[ (i / results->columns_) * x->columns_ + j]
                                    * y->data[i % results->rows_ + j * y->columns_];
            }

        }
    }

    static void sum(Matrix* x, Matrix* y, Matrix* results) {

        if ((!x) || (!y) || (!results)) {
            std::cout << "Error: one of matrices is not created"
                      << std::endl;
        }

        if ((x->columns_ != y->columns_) || (results->columns_ != y->columns_)
            || (x->rows_ != y->rows_) || (results->rows_ != x->rows_)) {
            std::cout << "Error : Ivalid dimensions of matrices for summation"
                      << std::endl;
        }

        int result_array_size = results->rows_ * results->columns_;

        for (int i = 0; i < result_array_size; ++i) {
                results->data[i] += x->data[i] + y->data[i];

        }
    }

    int get_rows_num() const;

    int get_columns_num() const;

    double get_value(int row_i, int col_i) const;
};

Matrix operator*(Matrix l, Matrix r);

Matrix operator+(Matrix l, Matrix r);

#endif // MATRIX_H
