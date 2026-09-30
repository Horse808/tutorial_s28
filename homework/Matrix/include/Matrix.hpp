#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix {
public:
    // 构造函数
    Matrix(int rows, int cols);
    // 拷贝构造函数
    Matrix(const Matrix &other);
    // 移动构造函数，思考和拷贝构造函数的区别
    Matrix(Matrix &&other);
    // 析构函数
    ~Matrix();

    // 设置矩阵元素
    Matrix &set(int row, int col, double value);
    // 获取矩阵元素
    double get(int row, int col) const;
    // 获取矩阵行
    double *getRow(int row) const;
    // 设置矩阵行
    Matrix &setRow(int row, double *values);
    // 获取矩阵列
    double *getCol(int col) const;
    // 设置矩阵列
    Matrix &setCol(int col, double *values);
    // 获取矩阵行数
    int getRows() const;
    // 获取矩阵列数
    int getCols() const;
    // 获取矩阵数据
    double **getData() const;

    // 打印矩阵
    Matrix &print() const;

    // 矩阵加法
    Matrix add(const Matrix &other) const;
    // 矩阵乘法
    Matrix multiply(const Matrix &other) const;
    // 矩阵转置
    Matrix transpose() const;
    // 矩阵求逆
    Matrix inverse() const;
    // 矩阵行列式
    double determinant() const;
    // 矩阵是否为方阵
    bool isSquare() const;

    // 重载运算符 + - * / = == !=, 实现矩阵的加减乘除赋值比较
    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator-() const;
    Matrix operator*(const Matrix &other) const;
    Matrix operator/(const Matrix &other) const;
    Matrix &operator=(const Matrix &other); // 赋值运算符
    Matrix &operator=(Matrix &&other); // 移动赋值运算符，思考和赋值运算符的区别
    bool operator==(const Matrix &other) const;
    bool operator!=(const Matrix &other) const;
    // 重载运算符 ()，实现矩阵的访问
    int operator()(int row, int col) const;
    int &operator()(int row, int col);
    // 重载运算符 <<，实现矩阵的输入，如：Matrix m(2, 2); m << 1, 2, 3, 4;
    Matrix &operator<<(double value);

    // 重载流运算符 <<，实现矩阵的输出
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

private:
    int rows; // 矩阵行数
    int cols; // 矩阵列数
    double **data; // 矩阵数据
};

#endif // MATRIX_HPP