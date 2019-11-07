#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Vector.h"

//Hàm đọc đọc vector nhập vào.
void Vector_Reader(string file, vector<float>& v)
{
	//Mở file.
	ifstream FileIn;
	FileIn.open(file, ios_base::in);

	//Đọc đến hết file và gán vào vector đã tạo.
	while (!FileIn.eof())
	{
		float value;
		FileIn >> value;
		v.push_back(value);
	}

	FileIn.close();
}

//Hàm xuất vector.
void Vector_Output(vector<float> v)
{
	int n = v.size();

	for (int i = 0; i < n; i++)
	{
		cout << v.at(i) << " ";
	}
}

//Hàm nhân vector với 1 số alpha.
void Vector_Multiply(vector<float> v, float k)
{
	int n = v.size();

	for (int i = 0; i < n; i++)
	{
		cout << v.at(i) * k << " ";
	}
}

//Hàm cộng hai vector.
void Vector_Sum(vector<float> v1, vector<float> v2)
{
	if (v1.size() != v2.size())
	{
		cout << "Khong the cong!" << endl;
		return;
	}
	else
	{
		vector<float> temp;

		temp.resize(v1.size());

		for (int i = 0; i < v1.size(); i++)
		{
			temp.at(i) = v1.at(i) + v2.at(i);
		}
		Vector_Output(temp);
	}
}