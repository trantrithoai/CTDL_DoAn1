#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

#include "Bool.h"

//Hàm đọc và vẽ biểu đồ.
void Read_Bool(string file, int**& arr)
{
	ifstream FileIn;
	FileIn.open(file, ios_base::in);//Mở file.

	arr = new int* [4];
	for (int i = 0; i < 4; i++)
	{
		arr[i] = new int[4];
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = 0;
		}
	}

	string str;
	FileIn >> str;

	int dem = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if(str.at(i) != ',' and str.at(i) != '.')
		{
			if (str.at(i) == 'x')
			{
				for (int k = 0; k < 4; k++)
				{
					arr[k][0] += 1;
					arr[k][1] += 1;
				}
			}
			else if (str.at(i) == '-' and str.at(i + 1) == 'x')
			{
				for (int k = 0; k < 4; k++)
				{
					arr[k][2] += 1;
					arr[k][3] += 1;
				}
				i++;
			}
			else if (str.at(i) == 'y')
			{
				for (int k = 0; k < 4; k++)
				{
					arr[k][1] += 1;
					arr[k][2] += 1;
				}
			}
			else if (str.at(i) == '-' and str.at(i + 1) == 'y')
			{
				for (int k = 0; k < 4; k++)
				{
					arr[k][0] += 1;
					arr[k][3] += 1;
				}
				i++;
			}
			else if (str.at(i) == 'z')
			{
				for (int k = 0; k < 4; k++)
				{
					arr[0][k] += 1;
					arr[1][k] += 1;
				}
			}
			else if (str.at(i) == '-' and str.at(i + 1) == 'z')
			{
				for (int k = 0; k < 4; k++)
				{
					arr[2][k] += 1;
					arr[3][k] += 1;
				}
				i++;
			}
			else if (str.at(i) == 't')
			{
				for (int k = 0; k < 4; k++)
				{
					arr[1][k] += 1;
					arr[2][k] += 1;
				}
			}
			else if (str.at(i) == '-' and str.at(i + 1) == 't')
			{
				for (int k = 0; k < 4; k++)
				{
					arr[0][k] += 1;
					arr[3][k] += 1;
				}
				i++;
			}
			dem++;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (arr[i][j] >= 10)
					{
						arr[i][j] = 10;
						continue;
					}		

					if (arr[i][j] == dem)
					{
						arr[i][j] = 10;
					}
					else
						arr[i][j] = 0;
				}
			}
			dem = 0;
		}
	}

	cout << "Bieu do:\n";

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "\t";
			
			std::cout << setw(1) << left << arr[i][j];
		}
		cout << endl;
	}

	FileIn.close();
}

void Bool(int** arr)
{
	string str = "";

	//Lấy tế bào 8 ô.
	int check = 1;

	for (int i = 0; i < 4; i++)
	{
		if (arr[i][0] >= 10 and arr[i][1] >= 10)
		{
			continue;
		}
		else
		{
			check = 0;
			break;
		}
	}

	if (check == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			arr[i][0] = 11;
			arr[i][1] = 11;
		}

		str += "x,";
	}

	check = 1;

	for (int i = 0; i < 4; i++)
	{
		if (arr[i][2] >= 10 and arr[i][3] >= 10)
		{
			continue;
		}
		else
		{
			check = 0;
			break;
		}
	}

	if (check == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			arr[i][2] = 11;
			arr[i][3] = 11;
		}

		str += "-x,";
	}

	check = 1;

	for (int i = 0; i < 4; i++)
	{
		if (arr[i][1] >= 10 and arr[i][2] >= 10)
		{
			continue;
		}
		else
		{
			check = 0;
			break;
		}
	}

	if (check == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			arr[i][1] = 11;
			arr[i][2] = 11;
		}

		str += "y,";
	}

	check = 1;

	for (int i = 0; i < 4; i++)
	{
		if (arr[i][0] >= 10 and arr[i][3] >= 10)
		{
			continue;
		}
		else
		{
			check = 0;
			break;
		}
	}

	if (check == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			arr[i][0] = 11;
			arr[i][3] = 11;
		}

		str += "-y,";
	}

	check = 1;

	for (int i = 0; i < 4; i++)
	{
		if (arr[0][i] >= 10 and arr[1][i] >= 10)
		{
			continue;
		}
		else
		{
			check = 0;
			break;
		}
	}

	if (check == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			arr[0][i] = 11;
			arr[1][i] = 11;
		}

		str += "z,";
	}

	check = 1;

	for (int i = 0; i < 4; i++)
	{
		if (arr[2][i] >= 10 and arr[3][i] >= 10)
		{
			continue;
		}
		else
		{
			check = 0;
			break;
		}
	}

	if (check == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			arr[2][i] = 11;
			arr[3][i] = 11;
		}

		str += "-z,";
	}

	check = 1;

	for (int i = 0; i < 4; i++)
	{
		if (arr[1][i] >= 10 and arr[2][i] >= 10)
		{
			continue;
		}
		else
		{
			check = 0;
			break;
		}
	}


	if (check == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			arr[1][i] = 11;
			arr[2][i] = 11;
		}

		str += "t,";
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 11)
				arr[i][j] = 18;
		}
	}
	/////////////////////////////////////////////////////////
	if (arr[0][0] >= 10 and arr[0][1] >= 10 and arr[1][0] >= 10 and arr[1][1] >= 10)
	{
		if (arr[0][0] < 18 or arr[0][1] < 18 or arr[1][0] < 18 or arr[1][1] < 18)
		{
			str += "xz,";
		}

		if (arr[0][0] < 18)
		{
			arr[0][0] = 14;
		}
		if (arr[0][1] < 18)
		{
			arr[0][1] = 14;
		}
		if (arr[1][0] < 18)
		{
			arr[1][0] = 14;
		}
		if (arr[1][1] < 18)
		{
			arr[1][1] = 14;
		}
	}

	if (arr[0][1] >= 10 and arr[0][2] >= 10 and arr[1][1] >= 10 and arr[1][2] >= 10)
	{
		if (arr[0][1] < 18 or arr[0][2] < 18 or arr[1][1] < 18 or arr[1][2] < 18)
		{
			str += "yz,";
		}

		if (arr[0][1] < 18)
		{
			arr[0][1] = 14;
		}
		if (arr[0][2] < 18)
		{
			arr[0][2] = 14;
		}
		if (arr[1][1] < 18)
		{
			arr[1][1] = 14;
		}
		if (arr[1][2] < 18)
		{
			arr[1][2] = 14;
		}
	}

	if (arr[0][2] >= 10 and arr[0][3] >= 10 and arr[1][2] >= 10 and arr[1][3] >= 10)
	{
		if (arr[0][2] < 18 or arr[0][3] < 18 or arr[1][2] < 18 or arr[1][3] < 18)
		{
			str += "-xz,";
		}

		if (arr[0][2] < 18)
		{
			arr[0][2] = 14;
		}
		if (arr[0][3] < 18)
		{
			arr[0][3] = 14;
		}
		if (arr[1][2] < 18)
		{
			arr[1][2] = 14;
		}
		if (arr[1][3] < 18)
		{
			arr[1][3] = 14;
		}
	}

	if (arr[0][0] >= 10 and arr[0][3] >= 10 and arr[1][0] >= 10 and arr[1][3] >= 10)
	{
		if (arr[0][0] < 18 or arr[0][3] < 18 or arr[1][0] < 18 or arr[1][3] < 18)
		{
			str += "-yz,";
		}

		if (arr[0][0] < 18)
		{
			arr[0][0] = 14;
		}
		if (arr[0][3] < 18)
		{
			arr[0][3] = 14;
		}
		if (arr[1][0] < 18)
		{
			arr[1][0] = 14;
		}
		if (arr[1][3] < 18)
		{
			arr[1][3] = 14;
		}
	}

	if (arr[1][0] >= 10 and arr[1][1] >= 10 and arr[2][0] >= 10 and arr[2][1] >= 10)
	{
		if (arr[1][0] < 18 or arr[1][1] < 18 or arr[2][0] < 18 or arr[2][1] < 18)
		{
			str += "xt,";
		}

		if (arr[1][0] < 18)
		{
			arr[1][0] = 14;
		}
		if (arr[1][1] < 18)
		{
			arr[1][1] = 14;
		}
		if (arr[2][0] < 18)
		{
			arr[2][0] = 14;
		}
		if (arr[2][1] < 18)
		{
			arr[2][1] = 14;
		}
	}

	if (arr[1][1] >= 10 and arr[1][2] >= 10 and arr[2][1] >= 10 and arr[2][2] >= 10)
	{
		if (arr[1][1] < 18 or arr[1][2] < 18 or arr[2][1] < 18 or arr[2][2] < 18)
		{
			str += "yt,";
		}

		if (arr[1][1] < 18)
		{
			arr[1][1] = 14;
		}
		if (arr[1][2] < 18)
		{
			arr[1][2] = 14;
		}
		if (arr[2][1] < 18)
		{
			arr[2][1] = 14;
		}
		if (arr[2][2] < 18)
		{
			arr[2][2] = 14;
		}
	}

	if (arr[1][2] >= 10 and arr[1][3] >= 10 and arr[2][2] >= 10 and arr[2][3] >= 10)
	{
		if (arr[1][2] < 18 or arr[1][3] < 18 or arr[2][2] < 18 or arr[2][3] < 18)
		{
			str += "-xt,";
		}

		if (arr[1][2] < 18)
		{
			arr[1][2] = 14;
		}
		if (arr[1][3] < 18)
		{
			arr[1][3] = 14;
		}
		if (arr[2][2] < 18)
		{
			arr[2][2] = 14;
		}
		if (arr[2][3] < 18)
		{
			arr[2][3] = 14;
		}
	}

	if (arr[1][0] >= 10 and arr[1][3] >= 10 and arr[2][0] >= 10 and arr[2][3] >= 10)
	{
		if (arr[1][0] < 18 or arr[1][3] < 18 or arr[2][0] < 18 or arr[2][3] < 18)
		{
			str += "-yt,";
		}

		if (arr[1][0] < 18)
		{
			arr[1][0] = 14;
		}
		if (arr[1][3] < 18)
		{
			arr[1][3] = 14;
		}
		if (arr[2][0] < 18)
		{
			arr[2][0] = 14;
		}
		if (arr[2][3] < 18)
		{
			arr[2][3] = 14;
		}
	}

	if (arr[2][0] >= 10 and arr[2][1] >= 10 and arr[3][0] >= 10 and arr[3][1] >= 10)
	{
		if (arr[2][0] < 18 or arr[2][1] < 18 or arr[3][0] < 18 or arr[3][1] < 18)
		{
			str += "x-z,";
		}

		if (arr[2][0] < 18)
		{
			arr[2][0] = 14;
		}
		if (arr[2][1] < 18)
		{
			arr[2][1] = 14;
		}
		if (arr[3][0] < 18)
		{
			arr[3][0] = 14;
		}
		if (arr[3][1] < 18)
		{
			arr[3][1] = 14;
		}
	}

	if (arr[2][1] >= 10 and arr[2][2] >= 10 and arr[3][1] >= 10 and arr[3][2] >= 10)
	{
		if (arr[2][1] < 18 or arr[2][2] < 18 or arr[3][1] < 18 or arr[3][2] < 18)
		{
			str += "y-z,";
		}

		if (arr[2][1] < 18)
		{
			arr[2][1] = 14;
		}
		if (arr[2][2] < 18)
		{
			arr[2][2] = 14;
		}
		if (arr[3][1] < 18)
		{
			arr[3][1] = 14;
		}
		if (arr[3][2] < 18)
		{
			arr[3][2] = 14;
		}
	}

	if (arr[2][2] >= 10 and arr[2][3] >= 10 and arr[3][2] >= 10 and arr[3][3] >= 10)
	{
		if (arr[2][2] < 18 or arr[2][3] < 18 or arr[3][2] < 18 or arr[3][3] < 18)
		{
			str += "-x-z,";
		}

		if (arr[2][2] < 18)
		{
			arr[2][2] = 14;
		}
		if (arr[2][3] < 18)
		{
			arr[2][3] = 14;
		}
		if (arr[3][2] < 18)
		{
			arr[3][2] = 14;
		}
		if (arr[3][3] < 18)
		{
			arr[3][3] = 14;
		}
	}

	if (arr[2][0] >= 10 and arr[2][3] >= 10 and arr[3][0] >= 10 and arr[3][3] >= 10)
	{
		if (arr[2][0] < 18 or arr[2][3] < 18 or arr[3][0] < 18 or arr[3][3] < 18)
		{
			str += "-y-z,";
		}

		if (arr[2][0] < 18)
		{
			arr[2][0] = 14;
		}
		if (arr[2][3] < 18)
		{
			arr[2][3] = 14;
		}
		if (arr[3][0] < 18)
		{
			arr[3][0] = 14;
		}
		if (arr[3][3] < 18)
		{
			arr[3][3] = 14;
		}
	}

	if (arr[0][0] >= 10 and arr[0][1] >= 10 and arr[3][0] >= 10 and arr[3][1] >= 10)
	{
		if (arr[0][0] < 18 or arr[0][1] < 18 or arr[3][0] < 18 or arr[3][1] < 18)
		{
			str += "x-t,";
		}

		if (arr[0][0] < 18)
		{
			arr[0][0] = 14;
		}
		if (arr[0][1] < 18)
		{
			arr[0][1] = 14;
		}
		if (arr[3][0] < 18)
		{
			arr[3][0] = 14;
		}
		if (arr[3][1] < 18)
		{
			arr[3][1] = 14;
		}
	}

	if (arr[0][1] >= 10 and arr[0][2] >= 10 and arr[3][1] >= 10 and arr[3][2] >= 10)
	{
		if (arr[0][1] < 18 or arr[0][2] < 18 or arr[3][1] < 18 or arr[3][2] < 18)
		{
			str += "y-t,";
		}

		if (arr[0][1] < 18)
		{
			arr[0][1] = 14;
		}
		if (arr[0][2] < 18)
		{
			arr[0][2] = 14;
		}
		if (arr[3][1] < 18)
		{
			arr[3][1] = 14;
		}
		if (arr[3][2] < 18)
		{
			arr[3][2] = 14;
		}
	}

	if (arr[0][2] >= 10 and arr[0][3] >= 10 and arr[3][2] >= 10 and arr[3][3] >= 10)
	{
		if (arr[0][2] < 18 or arr[0][3] < 18 or arr[3][2] < 18 or arr[3][3] < 18)
		{
			str += "-x-t,";
		}

		if (arr[0][2] < 18)
		{
			arr[0][2] = 14;
		}
		if (arr[0][3] < 18)
		{
			arr[0][3] = 14;
		}
		if (arr[3][2] < 18)
		{
			arr[3][2] = 14;
		}
		if (arr[3][3] < 18)
		{
			arr[3][3] = 14;
		}
	}

	if (arr[0][0] >= 10 and arr[0][3] >= 10 and arr[3][0] >= 10 and arr[3][3] >= 10)
	{
		if (arr[0][0] < 18 or arr[0][3] < 18 or arr[3][0] < 18 or arr[3][3] < 18)
		{
			str += "-y-t,";
		}

		if (arr[0][0] < 18)
		{
			arr[0][0] = 14;
		}
		if (arr[0][3] < 18)
		{
			arr[0][3] = 14;
		}
		if (arr[3][0] < 18)
		{
			arr[3][0] = 14;
		}
		if (arr[3][3] < 18)
		{
			arr[3][3] = 14;
		}
	}

	if (arr[0][0] >= 10 and arr[0][1] >= 10 and arr[0][2] >= 10 and arr[0][3] >= 10)
	{
		if (arr[0][0] < 18 or arr[0][1] < 18 or arr[0][2] < 18 or arr[0][3] < 18)
		{
			str += "z-t,";
		}

		if (arr[0][0] < 18)
		{
			arr[0][0] = 14;
		}
		if (arr[0][1] < 18)
		{
			arr[0][1] = 14;
		}
		if (arr[0][2] < 18)
		{
			arr[0][2] = 14;
		}
		if (arr[0][3] < 18)
		{
			arr[0][3] = 14;
		}
	}

	if (arr[1][0] >= 10 and arr[1][1] >= 10 and arr[1][2] >= 10 and arr[1][3] >= 10)
	{
		if (arr[1][0] < 18 or arr[1][1] < 18 or arr[1][2] < 18 or arr[1][3] < 18)
		{
			str += "zt,";
		}

		if (arr[1][0] < 18)
		{
			arr[1][0] = 14;
		}
		if (arr[1][1] < 18)
		{
			arr[1][1] = 14;
		}
		if (arr[1][2] < 18)
		{
			arr[1][2] = 14;
		}
		if (arr[1][3] < 18)
		{
			arr[1][3] = 14;
		}
	}

	if (arr[2][0] >= 10 and arr[2][1] >= 10 and arr[2][2] >= 10 and arr[2][3] >= 10)
	{
		if (arr[2][0] < 18 or arr[2][1] < 18 or arr[2][2] < 18 or arr[2][3] < 18)
		{
			str += "-zt,";
		}

		if (arr[2][0] < 18)
		{
			arr[2][0] = 14;
		}
		if (arr[2][1] < 18)
		{
			arr[2][1] = 14;
		}
		if (arr[2][2] < 18)
		{
			arr[2][2] = 14;
		}
		if (arr[2][3] < 18)
		{
			arr[2][3] = 14;
		}
	}

	if (arr[3][0] >= 10 and arr[3][1] >= 10 and arr[3][2] >= 10 and arr[3][3] >= 10)
	{
		if (arr[3][0] < 18 or arr[3][1] < 18 or arr[3][2] < 18 or arr[3][3] < 18)
		{
			str += "-z-t,";
		}

		if (arr[3][0] < 18)
		{
			arr[3][0] = 14;
		}
		if (arr[3][1] < 18)
		{
			arr[3][1] = 14;
		}
		if (arr[3][2] < 18)
		{
			arr[3][2] = 14;
		}
		if (arr[3][3] < 18)
		{
			arr[3][3] = 14;
		}
	}

	if (arr[0][0] >= 10 and arr[1][0] >= 10 and arr[2][0] >= 10 and arr[3][0] >= 10)
	{
		if (arr[0][0] < 18 or arr[1][0] < 18 or arr[2][0] < 18 or arr[3][0] < 18)
		{
			str += "x-y,";
		}

		if (arr[0][0] < 18)
		{
			arr[0][0] = 14;
		}
		if (arr[1][0] < 18)
		{
			arr[1][0] = 14;
		}
		if (arr[2][0] < 18)
		{
			arr[2][0] = 14;
		}
		if (arr[3][0] < 18)
		{
			arr[3][0] = 14;
		}
	}

	if (arr[0][1] >= 10 and arr[1][1] >= 10 and arr[2][1] >= 10 and arr[3][1] >= 10)
	{
		if (arr[0][1] < 18 or arr[1][1] < 18 or arr[2][1] < 18 or arr[3][1] < 18)
		{
			str += "xy,";
		}

		if (arr[0][1] < 18)
		{
			arr[0][1] = 14;
		}
		if (arr[1][1] < 18)
		{
			arr[1][1] = 14;
		}
		if (arr[2][1] < 18)
		{
			arr[2][1] = 14;
		}
		if (arr[3][1] < 18)
		{
			arr[3][1] = 14;
		}
	}

	if (arr[0][2] >= 10 and arr[1][2] >= 10 and arr[2][2] >= 10 and arr[3][2] >= 10)
	{
		if (arr[0][2] < 18 or arr[1][2] < 18 or arr[2][2] < 18 or arr[3][2] < 18)
		{
			str += "-xy,";
		}

		if (arr[0][2] < 18)
		{
			arr[0][2] = 14;
		}
		if (arr[1][2] < 18)
		{
			arr[1][2] = 14;
		}
		if (arr[2][2] < 18)
		{
			arr[2][2] = 14;
		}
		if (arr[3][2] < 18)
		{
			arr[3][2] = 14;
		}
	}

	if (arr[0][3] >= 10 and arr[1][3] >= 10 and arr[2][3] >= 10 and arr[3][3] >= 10)
	{
		if (arr[0][3] < 18 and arr[1][3] < 18 or arr[2][3] < 18 or arr[3][3] < 18)
		{
			str += "-x-y,";
		}

		if (arr[0][3] < 18)
		{
			arr[0][3] = 14;
		}
		if (arr[1][3] < 18)
		{
			arr[1][3] = 14;
		}
		if (arr[2][3] < 18)
		{
			arr[2][3] = 14;
		}
		if (arr[3][3] < 18)
		{
			arr[3][3] = 14;
		}
	}
	/////////////////////////////////////////////////////////
	if (arr[0][0] >= 10 and arr[0][1] >= 10)
	{
		if (arr[0][0] < 14 or arr[0][1] < 14)
		{
			str += "xz-t,";
		}

		if (arr[0][0] < 14)
		{
			arr[0][0] = 12;
		}
		if (arr[0][1] < 14)
		{
			arr[0][1] = 12;
		}
	}

	if (arr[0][1] >= 10 and arr[0][2] >= 10)
	{
		if (arr[0][1] < 14 or arr[0][2] < 14)
		{
			str += "yz-t,";
		}

		if (arr[0][1] < 14)
		{
			arr[0][1] = 12;
		}
		if (arr[0][2] < 14)
		{
			arr[0][2] = 12;
		}
	}

	if (arr[0][2] >= 10 and arr[0][3] >= 10)
	{
		if (arr[0][2] < 14 or arr[0][3] < 14)
		{
			str += "-xz-t,";
		}

		if (arr[0][2] < 14)
		{
			arr[0][2] = 12;
		}
		if (arr[0][3] < 14)
		{
			arr[0][3] = 12;
		}
	}

	if (arr[0][0] >= 10 and arr[0][3] >= 10)
	{
		if (arr[0][0] < 14 or arr[0][3] < 14)
		{
			str += "-yz-t,";
		}

		if (arr[0][0] < 14)
		{
			arr[0][0] = 12;
		}
		if (arr[0][3] < 14)
		{
			arr[0][3] = 12;
		}
	}
	/////////////////////////////
	if (arr[1][0] >= 10 and arr[1][1] >= 10)
	{
		if (arr[1][0] < 14 or arr[1][1] < 14)
		{
			str += "xzt,";
		}

		if (arr[1][0] < 14)
		{
			arr[1][0] = 12;
		}
		if (arr[1][1] < 14)
		{
			arr[1][1] = 12;
		}
	}

	if (arr[1][1] >= 10 and arr[1][2] >= 10)
	{
		if (arr[1][1] < 14 or arr[1][2] < 14)
		{
			str += "yzt,";
		}

		if (arr[1][1] < 14)
		{
			arr[1][1] = 12;
		}
		if (arr[1][2] < 14)
		{
			arr[1][2] = 12;
		}
	}

	if (arr[1][2] >= 10 and arr[1][3] >= 10)
	{
		if (arr[1][2] < 14 or arr[1][3] < 14)
		{
			str += "-xzt,";
		}

		if (arr[1][2] < 14)
		{
			arr[1][2] = 12;
		}
		if (arr[1][3] < 14)
		{
			arr[1][3] = 12;
		}
	}

	if (arr[1][0] >= 10 and arr[1][3] >= 10)
	{
		if (arr[1][0] < 14 or arr[1][3] < 14)
		{
			str += "-yzt,";
		}

		if (arr[1][0] < 14)
		{
			arr[1][0] = 12;
		}
		if (arr[1][3] < 14)
		{
			arr[1][3] = 12;
		}
	}
	////////////////////////////////////////////
	if (arr[2][0] >= 10 and arr[2][1] >= 10)
	{
		if (arr[2][0] < 14 or arr[2][1] < 14)
		{
			str += "x-zt,";
		}

		if (arr[2][0] < 14)
		{
			arr[2][0] = 12;
		}
		if (arr[2][1] < 14)
		{
			arr[2][1] = 12;
		}
	}

	if (arr[2][1] >= 10 and arr[2][2] >= 10)
	{
		if (arr[2][1] < 14 or arr[2][2] < 14)
		{
			str += "y-zt,";
		}

		if (arr[2][1] < 14)
		{
			arr[2][1] = 12;
		}
		if (arr[2][2] < 14)
		{
			arr[2][2] = 12;
		}
	}

	if (arr[2][2] >= 10 and arr[2][3] >= 10)
	{
		if (arr[2][2] < 14 or arr[2][3] < 14)
		{
			str += "-x-zt,";
		}

		if (arr[2][2] < 14)
		{
			arr[2][2] = 12;
		}
		if (arr[2][3] < 14)
		{
			arr[2][3] = 12;
		}
	}

	if (arr[2][0] >= 10 and arr[2][3] >= 10)
	{
		if (arr[2][0] < 14 or arr[2][3] < 14)
		{
			str += "-y-zt,";
		}

		if (arr[2][0] < 14)
		{
			arr[2][0] = 12;
		}
		if (arr[2][3] < 14)
		{
			arr[2][3] = 12;
		}
	}
	//////////////////////////////////////////
	if (arr[3][0] >= 10 and arr[3][1] >= 10)
	{
		if (arr[3][0] < 14 or arr[3][1] < 14)
		{
			str += "x-z-t,";
		}

		if (arr[3][0] < 14)
		{
			arr[3][0] = 12;
		}
		if (arr[3][1] < 14)
		{
			arr[3][1] = 12;
		}
	}

	if (arr[3][1] >= 10 and arr[3][2] >= 10)
	{
		if (arr[3][1] < 14 or arr[3][2] < 14)
		{
			str += "y-z-t,";
		}

		if (arr[3][1] < 14)
		{
			arr[3][1] = 12;
		}
		if (arr[3][2] < 14)
		{
			arr[3][2] = 12;
		}
	}

	if (arr[3][2] >= 10 and arr[3][3] >= 10)
	{
		if (arr[3][2] < 14 or arr[3][3] < 14)
		{
			str += "-x-z-t,";
		}

		if (arr[3][2] < 14)
		{
			arr[3][2] = 12;
		}
		if (arr[3][3] < 14)
		{
			arr[3][3] = 12;
		}
	}

	if (arr[3][0] >= 10 and arr[3][3] >= 10)
	{
		if (arr[3][0] < 14 or arr[3][3] < 14)
		{
			str += "-y-z-t,";
		}

		if (arr[3][0] < 14)
		{
			arr[3][0] = 12;
		}
		if (arr[3][3] < 14)
		{
			arr[3][3] = 12;
		}
	}
	//////////////////////////////////////////
	if (arr[0][0] >= 10 and arr[1][0] >= 10)
	{
		if (arr[0][0] < 14 or arr[1][0] < 14)
		{
			str += "x-yz,";
		}

		if (arr[0][0] < 14)
		{
			arr[0][0] = 12;
		}
		if (arr[1][0] < 14)
		{
			arr[1][0] = 12;
		}
	}

	if (arr[1][0] >= 10 and arr[2][0] >= 10)
	{
		if (arr[1][0] < 14 or arr[2][0] < 14)
		{
			str += "x-yt,";
		}

		if (arr[1][0] < 14)
		{
			arr[1][0] = 12;
		}
		if (arr[2][0] < 14)
		{
			arr[2][0] = 12;
		}
	}

	if (arr[2][0] >= 10 and arr[3][0] >= 10)
	{
		if (arr[2][0] < 14 or arr[3][0] < 14)
		{
			str += "x-y-z,";
		}

		if (arr[2][0] < 14)
		{
			arr[2][0] = 12;
		}
		if (arr[3][0] < 14)
		{
			arr[3][0] = 12;
		}
	}

	if (arr[0][0] >= 10 and arr[3][0] >= 10)
	{
		if (arr[0][0] < 14 or arr[3][0] < 14)
		{
			str += "x-y-t,";
		}

		if (arr[0][0] < 14)
		{
			arr[0][0] = 12;
		}
		if (arr[3][0] < 14)
		{
			arr[3][0] = 12;
		}
	}
	/////////////////////////////////////////////
	if (arr[0][1] >= 10 and arr[1][1] >= 10)
	{
		if (arr[0][1] < 14 or arr[1][1] < 14)
		{
			str += "xyz,";
		}

		if (arr[0][1] < 14)
		{
			arr[0][1] = 12;
		}
		if (arr[1][1] < 14)
		{
			arr[1][1] = 12;
		}
	}

	if (arr[1][1] >= 10 and arr[2][1] >= 10)
	{
		if (arr[1][1] < 14 or arr[2][1] < 14)
		{
			str += "xyt,";
		}

		if (arr[1][1] < 14)
		{
			arr[1][1] = 12;
		}
		if (arr[2][1] < 14)
		{
			arr[2][1] = 12;
		}
	}

	if (arr[2][1] >= 10 and arr[3][1] >= 10)
	{
		if (arr[2][1] < 14 or arr[3][1] < 14)
		{
			str += "xy-z,";
		}

		if (arr[2][1] < 14)
		{
			arr[2][1] = 12;
		}
		if (arr[3][1] < 14)
		{
			arr[3][1] = 12;
		}
	}

	if (arr[0][1] >= 10 and arr[3][1] >= 10)
	{
		if (arr[0][1] < 14 or arr[3][1] < 14)
		{
			str += "xy-t,";
		}

		if (arr[0][1] < 14)
		{
			arr[0][1] = 12;
		}
		if (arr[3][1] < 14)
		{
			arr[3][1] = 12;
		}
	}
	/////////////////////////////////////////////////////////
	if (arr[0][2] >= 10 and arr[1][2] >= 10)
	{
		if (arr[0][2] < 14 or arr[1][2] < 14)
		{
			str += "-xyz,";
		}

		if (arr[0][2] < 14)
		{
			arr[0][2] = 12;
		}
		if (arr[1][2] < 14)
		{
			arr[1][2] = 12;
		}
	}

	if (arr[1][2] >= 10 and arr[2][2] >= 10)
	{
		if (arr[1][2] < 14 or arr[2][2] < 14)
		{
			str += "-xyt,";
		}

		if (arr[1][2] < 14)
		{
			arr[1][2] = 12;
		}
		if (arr[2][2] < 14)
		{
			arr[2][2] = 12;
		}
	}

	if (arr[2][2] >= 10 and arr[3][2] >= 10)
	{
		if (arr[2][2] < 14 or arr[3][2] < 14)
		{
			str += "-xy-z,";
		}

		if (arr[2][2] < 14)
		{
			arr[2][2] = 12;
		}
		if (arr[3][2] < 14)
		{
			arr[3][2] = 12;
		}
	}

	if (arr[0][2] >= 10 and arr[3][2] >= 10)
	{
		if (arr[0][2] < 14 or arr[3][2] < 14)
		{
			str += "-xy-t,";
		}

		if (arr[0][2] < 14)
		{
			arr[0][2] = 12;
		}
		if (arr[3][2] < 14)
		{
			arr[3][2] = 12;
		}
	}
	///////////////////////////////////////////////////////////////
	if (arr[0][3] >= 10 and arr[1][3] >= 10)
	{
		if (arr[0][3] < 14 or arr[1][3] < 14)
		{
			str += "-x-yz,";
		}

		if (arr[0][3] < 14)
		{
			arr[0][3] = 12;
		}
		if (arr[1][3] < 14)
		{
			arr[1][3] = 12;
		}
	}

	if (arr[1][3] >= 10 and arr[2][3] >= 10)
	{
		if (arr[1][3] < 14 or arr[2][3] < 14)
		{
			str += "-x-yt,";
		}

		if (arr[1][3] < 14)
		{
			arr[1][3] = 12;
		}
		if (arr[2][3] < 14)
		{
			arr[2][3] = 12;
		}
	}

	if (arr[2][3] >= 10 and arr[3][3] >= 10)
	{
		if (arr[2][3] < 14 or arr[3][3] < 14)
		{
			str += "-x-y-z,";
		}

		if (arr[2][3] < 14)
		{
			arr[2][3] = 12;
		}
		if (arr[3][3] < 14)
		{
			arr[3][3] = 12;
		}
	}

	if (arr[0][3] >= 10 and arr[3][3] >= 10)
	{
		if (arr[0][3] < 14 or arr[3][3] < 14)
		{
			str += "-x-y-t,";
		}

		if (arr[0][3] < 14)
		{
			arr[0][3] = 12;
		}
		if (arr[3][3] < 14)
		{
			arr[3][3] = 12;
		}
	}
	//////////////////////////////////////////////////


	cout << str;

	cout << "\nBieu do:\n";

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "\t";

			std::cout << setw(1) << left << arr[i][j];
		}
		cout << endl;
	}

}