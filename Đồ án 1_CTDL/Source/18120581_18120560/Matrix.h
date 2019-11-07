#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_

//Hàm đọc ma trận từ file gán vào mảng 2 chiều và đọc vế phải.
void Matrix_Reader(string file, float**& arr, int& rows, int& cols, float*& vp);

//Hàm xuất ma trận ra màn hình.
void Matrix_Output(float** arr, int rows, int cols);

//Hàm tính định thức của ma trận vuông.(Đệ quy)
float Matrix_Determinant(float** arr, int rank);

//Hàm tìm định thức của ma trận con bỏ đi dòng rows cột cols.
float Matrix_Child(float** arr, int rank, int rows, int cols);

//Hàm tìm ma trận nghịch đảo.
void Matrix_Inverse(float** arr, int n);

//Hàm tính tích 2 ma trận.
void Matrix_Multiply(float** arr1, int rows1, int cols1, float** arr2, int rows2, int cols2);

//Hàm tìm hạng của ma trận.
int Matrix_Rank(float** arr, int cols, int rows);

float DetChangePos(float** arr, int rows, int cols, const float* vp, int changepos);

//Hàm giải hệ phương trình tuyến tính ma trận.
void Matrix_Linear(float** arr, int rows, int cols, float* vp);

bool Exist(int* a, int index, int length);

#endif // !_MATRIX_H_

