#include "head.h"

int main()
{
	vector<vector<int>> arr;
	arr.resize(9);
	for (int i = 0; i < 9; ++i)
	{
		char *buf = new char[10];
		cin >> buf;
		for (int j = 0; j < 9; ++j)
		{
			arr[i].push_back(int(buf[j]) - 48); // int('0')==48
		}
		delete[] buf;
	}

	chrono::system_clock::time_point start, end;
	start = std::chrono::system_clock::now();

	if (solve_sudoku(arr, 0, 0) == 1)
	{
		cout << "--- :) Done!!! ---" << endl;
		for (int i = 0; i < 9; i++)
		{
			cout << '|';
			for (int j = 0; j < 8; j++)
			{
				cout << arr[i][j] << '|';
			}
			cout << arr[i][8];
			cout << '|' << endl;
		}
	}
	else
	{
		cout << "--- :( didn't solve... ---" << endl;
	}
	end = std::chrono::system_clock::now();
	double elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << "took " << elapsed << " μs\n";

	return 0;
}