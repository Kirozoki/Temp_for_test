#include "matrix.h"

Matrix::Matrix(int n, int m) : data(n * m, 0.0), rows_(n), columns_(m) {
}

Matrix &Matrix::operator=(const Matrix &other) {
    data = other.data;
    rows_ = other.rows_;
    columns_ = other.columns_;
    return *this;
}

Matrix &Matrix::operator*=(Matrix other) {
    if (columns_ != other.rows_) {
        std::cerr << "Error: trial of multiplication of non-compatible "
                     "matrices i.e. number of columns of the 1st doesn't "
                     "equal to one of rows of the 2nd" << std::endl;
        return *this;
    }
    Matrix result(rows_, other.columns_);
    multiply(this, &other, &result);
    *this = std::move(result);
    return *this;
}

Matrix &Matrix::operator+=(Matrix other) {
    if ((columns_ != other.columns_) || (rows_ != other.rows_)) {
        std::cerr << "Error: trial of summation of non-compatible "
                     "matrices i.e. their dimensions are not equal" << std::endl;
        return *this;
    }
    Matrix result(rows_, columns_);
    sum(this, &other, &result);
    *this = std::move(result);
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) {
    data = std::move(other.data);
    rows_ = other.rows_;
    columns_ = other.columns_;
    return *this;
}

void Matrix::set_value(int row, int col, double value) { // row from 0 to rows_ - 1, col from 0 to columns_ - 1
    data[row * columns_ + col] = value;
}

int Matrix::get_rows_num() const {
    return rows_;
}

int Matrix::get_columns_num() const {
    return columns_;
}

double Matrix::get_value(int row_i, int col_i) const {
    return data.at(row_i * columns_ + col_i);
}

Matrix operator*(Matrix l, Matrix r) {
    return l *= r;
}

Matrix operator+(Matrix l, Matrix r) {
    return l += r;
}
