#include <iostream>
#include <iomanip>//Thư viện của hàm setw().
#include <fstream>//Thư viện hỗ trợ đọc file.
#include <math.h>//Thư viện hỗ trợ hàm roundf.
using namespace std;

#include "Matrix.h"

//Hàm đọc ma trận từ file gán vào mảng 2 chiều và đọc vế phải.
void Matrix_Reader(string file, float**& arr, int& rows, int& cols, float*& vp)
{
	ifstream FileIn;
	FileIn.open(file, ios_base::in);//Mở file.

	FileIn >> rows;//Đọc số dòng.
	FileIn >> cols;//Đọc số cột.

	arr = new float* [rows];//Khởi tạo mảng 2 chiều.

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new float[cols];//Khởi tạo mảng 1 chiều của arr[i].

		for (int j = 0; j < cols; j++)
		{
			FileIn >> arr[i][j];//Đọc và chép vào mảng.
		}
	}

	//Khởi tạo mảng 1 chiều cho vế phải.
	vp = new float[rows];

	for (int i = 0; i < rows; i++)
	{
		FileIn >> vp[i];//Đọc và chép vào mảng.
	}

	FileIn.close();//Đóng file.
}

//Hàm xuất ma trận ra màn hình.
void Matrix_Output(float** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "\t";
			//Căn lề bên trái và xuất từng phần tử của mảng làm tròn 3 chữ số sau số 0.
			std::cout << setw(1) << left << roundf(arr[i][j]*1000)/1000;
		}
		cout << endl;
	}
}

//Hàm tính định thức của ma trận vuông.(Đệ quy)
float Matrix_Determinant(float** arr, int rank)
{
	int s, det = 0;

	if (rank == 1)//Nếu ma trận cấp 1.
	{
		return arr[0][0];//Trả về phần tử duy nhất của ma trận.
	}

	if (rank == 2)//Nếu ma trận cấp 2.
	{
		//Trả về tích đường chéo chính trừ đường chéo phụ.
		return (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);
	}

	//Nếu bậc của ma trận từ 3 trở lên thì ta sẽ chia nhỏ ma trận từ n->1,2 và tìm det.
	//Tạo ra một ma trận nhỏ hơn.
	float** smaller;

	for (int k = 0; k < rank; k++)
	{
		 smaller = new float* [rank];

		 //Thuật toán: Ma trận smaller này sẽ là ma trận gốc bỏ đi hàng i cột j và từ đó
		 //tính det của ma trận smaller này
		 //Biến i chạy theo cột.
		for (int i = 0; i < rank; i++)
		{
			smaller[i] = new float[rank];

			//Biến j chạy theo hàng.
			for (int j = 1; j < rank; j++)
			{
				if (i < k)
				{
					smaller[i][j - 1] = arr[i][j];
				}
				else if (i > k)
				{
					smaller[i - 1][j - 1] = arr[i][j];
				}
			}
		}

		//Biến s mang giá trị 1 nếu k chẵn và -1 nếu k lẻ vì: s = (-1)^k.
		if (k % 2 == 0)
		{
			s = 1;
		}
		else
		{
			s = -1;
		}

		//Cộng dồn det của các ma trận nhỏ lại.
		det += arr[k][0] * s * Matrix_Determinant(smaller, rank - 1);

		delete[] smaller;
	}

	//Xuất kết quả định thức.
	return det;
}

//Hàm tìm định thức của ma trận con bỏ đi dòng rows cột cols.
float Matrix_Child(float** arr, int rank, int rows, int cols)
{
	int  x = -1, y;

	//Khởi tạo ma trận con b.
	float** b = new float* [rank];

	for (int i = 0; i < rank; i++)
	{
		b[i] = new float[rank];

		if (i == rows) continue;//Bỏ dòng h.
		x++;
		y = -1;

		for (int j = 0; j < rank; j++)
		{
			if (j == cols)//Bỏ dòng c
				continue;
			y++;
			b[x][y] = arr[i][j];//Gán giá trị vào cho ma trận con.
		}
	}

	//Điều kiện: (-1)^(rows + cols)*det.
	if ((rows + cols) % 2 == 0)
	{
		return Matrix_Determinant(b, rank - 1);
	}

	return 	-Matrix_Determinant(b, rank - 1);
}

//Hàm tìm ma trận nghịch đảo.
void Matrix_Inverse(float** arr, int rank)
{
	//Khởi tạo ma trận b cùng bậc với ma trận ban đầu.
	float** b = new float* [rank];

	for (int i = 0; i < rank; i++)
	{
		b[i] = new float[rank];

		for (int j = 0; j < rank; j++)
		{
			//Gán từng phần tử của b là det của ma trận con bỏ đi dòng i cột j.
			b[i][j] = Matrix_Child(arr, rank, i, j);
		}
	}

	//Biến ma trận b thành ma trận chuyển vị.
	for (int i = 0; i < rank - 1; i++)
	{
		for (int j = i + 1; j < rank; j++)
		{
			//Hoán vị 2 phần tử đối xứng qua đường chéo chính.
			swap(b[i][j], b[j][i]);
		}
	}

	//Lấy giá trị định thức của ma trận arr.
	float det = Matrix_Determinant(arr, rank);

	//Nhân ma trận với 1/det.
	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			b[i][j] /= det;
		}
	}

	//Xuất ma trận nghịch đảo.
	Matrix_Output(b, rank, rank);

	//Giải phóng bộ nhớ.
	delete[] b;
}

//Hàm tính tích 2 ma trận.
void Matrix_Multiply(float** arr1, int rows1, int cols1, float** arr2, int rows2, int cols2)
{
	//Điều kiện số cột ma trận 1 = số hàng ma trận 2
	if (cols1 == rows2)
	{
		//Khởi tạo ma trận b với số hàng của ma trận 1 và số cột của ma trận 2.
		float** b = new float* [rows1];

		for (int i = 0; i < rows1; i++)
		{
			b[i] = new float[cols2];

			for (int j = 0; j < cols2; j++)
			{
				int temp = 0;

				//Lấy phần tử hàng i nhân lần lượt với cột j của ma trận 2.
				for (int k = 0; k < cols1; k++)
				{
					temp += arr1[i][k] * arr2[k][j];
				}
				b[i][j] = temp;
			}

		}

		cout << "\n\n========Tich hai ma tran la:========" << endl;
		Matrix_Output(b, rows1, cols2);

		//Giải phóng bộ nhớ.
		delete[] b;
	}
	//Kiểm tra thêm hàng của ma trận 1 và cột ma trận 2.
	else if (rows1 == cols2)
	{
		//Tính tích bằng cách đổi chỗ thứ tự 2 ma trận.
		Matrix_Multiply(arr2, rows2, cols2, arr1, rows1, cols1);
	}
	else
	{
		cout << "\n\nHai ma tran khong nhan duoc." << endl;
	}
}

//Hàm tìm hạng của ma trận.
int Matrix_Rank(float** arr, int rows, int cols)
{
	//Tạo ra mảng copy của ma trận.
	float** temp = new float* [rows];

	//Gán mảng temp này là ma trận ban đầu.
	for (int i = 0; i < rows; i++)
	{
		temp[i] = new float[cols];

		for (int j = 0; j < cols; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}

	//Khởi tạo giá trị hạng ban đầu là số dòng.
	int rank = rows;

	//Biến i chạy theo hàng.
	for (int i = 0; i < rows; i++)
	{
		//Biến j chạy theo cột.
		for (int j = 0; j < cols; j++)
		{
			//Nếu phần tử ma trận  = 0.
			if (temp[i][j] == 0)
			{
				//Biến r chạy trước i 1 đơn vị theo hàng.
				for (int r = i + 1; r < rows; r++)
				{
					//Nếu phần tử tại đó khác 0.
					if (temp[r][j] != 0)
					{
						//Biến c chạy theo hàng từ vị trí đầu.
						for (int c = 0; c < cols; c++)
						{
							//Hoán đổi hàng.
							swap(temp[r][c], temp[i][c]);
						}
						break;
					}	
				}
			}
			else
				break;
		}
	}

	//Xét duyệt từng phần tử trong mảng.
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int r;
			//Nếu phần tử  0.
			if (temp[i][j] != 0)
			{
				//Biến r = i+1.
				r = i + 1;

				//Chạy biến r đến hết hàng.
				while (r < rows)
				{
					//Lấy hệ số giữa 2 phần tử.
					float k = temp[r][j] / temp[i][j];

					//Chia 2 hàng với hệ số k vừa lấy.
					for (int c = 0; c < cols; c++)
					{
						temp[r][c] = temp[r][c] - k * temp[i][c];
					}
					//Tăng biến r cho đến hết hàng.
					r++;
				}
			}
		}
	}

	//Kiểm tra xem có những cặp hàng nào tỉ lệ với nhau không.
	//vd:  0 1 2 3 và 0 2 4 6 tỉ lệ với k = 2.
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = i + 1; j < rows; j++)
		{
			//Hai vòng for trên là xét từng cặp hàng với nhau.
			for (int k = 0; k < cols; k++)
			{
				//Nếu 2 phần tử cùng cột đều bằng 0 thì bỏ qua.
				if (temp[i][k] == 0 and temp[j][k] == 0)
				{
					continue;
				}
				//Nếu có 1 phần tử bằng 0 thì không thể tỉ lệ với hệ số 0.
				else if (temp[i][k] == 0 or temp[j][k] == 0)
				{
					break;
				}
				else
				{
					//Ta lấy tỉ số h giữa 2 phần tử.
					float h = temp[i][k] / temp[j][k];

					//Cho cờ hiệu là đúng.
					int flag = 1;

					//Kiểm tra nếu có bất kì cặp phần tử cùng cột nào không thỏa tỉ lệ trên thì dừng.
					for (int l = k + 1; l < cols; l++)
					{
						if (temp[i][l] / temp[j][l] != h)
						{
							flag = 0;
							break;
						}
					}

					//Nếu tất cả đều thỏa thì gán cả hàng là 0;
					if (flag == 1)
					{
						for (int n = 0; n < cols; n++)
						{
							temp[i][n] = 0;
						}
					}
				}
			}
		}
	}
	
	//Đếm số hàng bằng 0 và trừ vào rank ban đầu.
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//Nếu có 1 phần tử khác 0 thì hàng đó bỏ qua.
			if (temp[i][j] != 0)
				break;
			else
				//Nếu đến hết hàng tất cả đều bằng 0 thì rank--.
				if (j == cols - 1)
					rank--;
		}
	}

	//Giải phóng bộ nhớ.
	delete[] temp;

	//Xuất hạng của ma trận.
	return rank;
}

//Hàm tính định thức ma trận thế vế phải vào ma trận.
float DetChangePos(float** arr, int rows, int cols, const float* vp, int changepos)
{
	float det;

	//Khởi tạo ma trận copy.
	float** copyarr = new float* [rows];

	for (int i = 0; i < rows; i++)
	{
		copyarr[i] = new float[cols];
	}

	//Copy ma trận
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			copyarr[i][j] = arr[i][j];
		}
	}

	//Thế vế phải.
	for (int i = 0; i < rows; i++)
	{
		copyarr[i][changepos] = vp[i];
	}

	//Tính định thức.
	det = Matrix_Determinant(copyarr, rows);

	delete[] copyarr;

	return det;
}

//Hàm giải hệ phương trình tuyến tính ma trận.
void Matrix_Linear(float** arr, int rows, int cols, float* vp)
{
	//Khởi tạo ma trận copy.
	float** copyarr1 = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		copyarr1[i] = new float[cols];
	}

	//Khởi tạo ma trận copy và có vế phải.
	float** copyarr2 = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		copyarr2[i] = new float[cols + 1];
	}

	//Copy ma trận.
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			copyarr1[i][j] = arr[i][j];
			copyarr2[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		copyarr2[i][cols] = vp[i];
	}

	//Lấy hạng của ma trận.
	int r1 = Matrix_Rank(copyarr1, rows, cols);

	int r2 = Matrix_Rank(copyarr2, rows, cols + 1);

	//Nếu hạng khác nhau thì kết luận hệ vô nghiệm.
	if (r1 != r2)
	{
		cout << "\nHe vo nghiem";

	}
	else
	{
		//Nếu hạng ma trận bằng số vector thì hệ có nghiệm duy nhất.
		if (r1 == cols)
		{
			//Tạo mảng định thức.
			float* ArrDet = new float[cols];
			for (int i = 0; i < cols; i++)
			{
				ArrDet[i] = DetChangePos(copyarr1, rows, cols, vp, i);
			}

			cout << "\nHe co nghiem duy nhat : ";

			float det = Matrix_Determinant(copyarr1, cols);

			for (int i = 0; i < cols; i++)
			{
				cout << "x" << i + 1 << "=" << ArrDet[i] / det << " ";
			}

			delete[]ArrDet;
		}
		else
		{
			cout << "\nHe vo so nghiem voi " << cols - r1 << " an tu do!";
		}
	}

	delete[] copyarr1, copyarr2;
}
