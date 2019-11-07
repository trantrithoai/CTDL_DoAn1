#pragma once
#ifndef _VECTOR_H_
#define _VECTOR_H_

//Hàm đọc vector nhập vào.
void Vector_Reader(string file, vector<float>& v);

//Hàm xuất vector.
void Vector_Output(vector<float> v);

//Hàm nhân vector với 1 số alpha.
void Vector_Multiply(vector<float> v, float k);

//Hàm cộng hai vector.
void Vector_Sum(vector<float> v1, vector<float> v2);

#endif // !_VECTOR_H_
