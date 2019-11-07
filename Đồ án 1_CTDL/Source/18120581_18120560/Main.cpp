#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
using namespace std;

#include "Matrix.h"
#include "Vector.h"
#include "Bool.h"

int main()
{
	cout << "\t\tXIN CHAO CAC BAN DA DEN VOI CHUONG TRINH" << endl;
	Sleep(1500);//Dừng màn hình 1.5 giây.
	cout << "\t\tPHAN MEM NAY HO TRO BAN HOC TAP" << endl;
	Sleep(2000);//Dừng màn hình 2 giây.

	system("cls");//Xóa màn hình.

	int choose;
	do
	{
		system("cls");

		cout << "\t================== Menu ==================" << endl;
		cout << "\tNhap lua chon 1: Tim cong thuc da toi thieu cua ham bool." << endl;
		cout << "\tNhap lua chon 2: Lam phep toan tren vector." << endl;
		cout << "\tNhap lua chon 3: Lam phep toan tren ma tran." << endl;
		cout << "\tCon lai la thoat chuong trinh." << endl;

		cout << "\nNhap lua chon: ";
		cin >> choose;

		if (choose == 1)
		{
			int** arr;
			Read_Bool("bool.txt", arr);

			cout << "\nCong thuc da thuc toi thieu la: ";
			Bool(arr);

			delete[] arr;
		}
		else if (choose == 2)
		{
			//Khởi tạo vector 1 và chép vào vector.
			vector<float> vector1;
			Vector_Reader("vector1.txt", vector1);

			//Xuất vector.
			cout << "\nVector 1 la: ";
			Vector_Output(vector1);

			//Nhân vector 1 với 1 số alpha.
			float k;
			cout << "\nBan muon nhan vector 1 voi bao nhieu: ";
			cin >> k;

			cout << "Ket qua: ";
			Vector_Multiply(vector1, k);

			//Khởi tạo vector 2 và chép vào vector.
			vector<float> vector2;
			Vector_Reader("vector2.txt", vector2);

			//Xuất vector.
			cout << "\n\nVector 2 la: ";
			Vector_Output(vector2);

			//Nhân vector 2 với 1 số alpha.
			cout << "\nBan muon nhan vector 2 voi bao nhieu: ";
			cin >> k;

			cout << "Ket qua: ";
			Vector_Multiply(vector2, k);

			cout << "\n\nKet qua khi cong hai vector: ";
			Vector_Sum(vector1, vector2);
		}
		else if (choose == 3)
		{
			//Ma trận 1.
			float** arr1;
			float* vp1;
			int rows1, cols1;

			//Đọc ma trận 1.
			Matrix_Reader("matrix_1.txt", arr1, rows1, cols1, vp1);

			//Xuất ma trận 1.
			cout << "\n========= Ma tran 1: =========\n";
			Matrix_Output(arr1, rows1, cols1);

			//Tìm định thức ma trận 1.
			cout << "\nDinh thuc cua ma tran: ";

			//Điều kiện là ma trận vuông.
			if (rows1 == cols1)
			{
				cout << Matrix_Determinant(arr1, rows1);
			}
			else
			{
				cout << "Khong co!";
			}

			//Tìm ma trận nghịch đảo của ma trận 1.
			cout << "\nMa tran nghich dao la: ";

			//Điều kiện là ma trận vuông và định thức khác 0.
			if (rows1 == cols1 and Matrix_Determinant(arr1, rows1) != 0)
			{
				cout << endl;
				Matrix_Inverse(arr1, rows1);
			}
			else
			{
				cout << "Khong co!\n";
			}

			cout << "Hang cua ma tran: " << Matrix_Rank(arr1, rows1, cols1);

			//Giải hệ phương trình tuyến tính của ma trận 1.
			Matrix_Linear(arr1, rows1, cols1, vp1);

			//Ma trận 2.
			float** arr2;
			float* vp2;
			int rows2, cols2;

			//Đọc ma trận 2.
			Matrix_Reader("matrix_2.txt", arr2, rows2, cols2, vp2);

			//Xuất ma trận 2.
			cout << "\n\n========= Ma tran 2: =========\n";
			Matrix_Output(arr2, rows2, cols2);

			//Tìm định thức ma trận 2.
			cout << "\nDinh thuc cua ma tran: ";

			//Điều kiện là ma trận vuông.
			if (rows2 == cols2)
			{
				cout << Matrix_Determinant(arr2, rows2);
			}
			else
			{
				cout << "Khong co!";
			}

			//Tìm ma trận nghịch đảo của ma trận 2.
			cout << "\nMa tran nghich dao la: ";

			//Điều kiện là ma trận vuông và định thức khác 0.
			if (rows2 == cols2 and Matrix_Determinant(arr2, rows2) != 0)
			{
				cout << endl;
				Matrix_Inverse(arr2, rows2);
			}
			else
			{
				cout << "Khong co!\n";
			}

			cout << "Hang cua ma tran: " << Matrix_Rank(arr2, rows2, cols2);

			//Giải hệ phương trình tuyến tính của ma trận 2.
			Matrix_Linear(arr2, rows2, cols2, vp2);

			//Nhân hai ma trận.
			Matrix_Multiply(arr1, rows1, cols1, arr2, rows2, cols2);

			//Giải phóng bộ nhớ.
			delete[] arr1, arr2, vp1, vp2;
		}
		else
		{
			cout << "\nCam on ban da dung chuong trinh. Hen gap lai.";
		}

		system("pause");

	} while (choose == 1 || choose == 2 || choose == 3);

	return 0;
}