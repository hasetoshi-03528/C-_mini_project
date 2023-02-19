#include "head.h"

bool check_vertically(vector<vector<int>> &arr, int x, int n)
// 縦の確認
{
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][x] == n)
		{
			return false;
		}
	}
	return true;
}

bool check_horizontally(vector<vector<int>> &arr, int y, int n)
// 横の確認
{
	for (int i = 0; i < 9; ++i)
	{
		if (arr[y][i] == n)
		{
			return false;
		}
	}
	return true;
}

bool check_mass(vector<vector<int>> &arr, int x, int y, int n)
// 3*3マスでの確認
{
	int x_base = (x / 3) * 3;
	int y_base = (y / 3) * 3;
	for (int i = x_base; i < (x_base + 3); ++i)
	{
		for (int j = y_base; j < (y_base + 3); j++)
		{
			if (arr[j][i] == n)
			{
				return false;
			}
		}
	}
	return true;
}

int change_num(vector<vector<int>> &arr, int x, int y, int n)
// n:1~9での置き換えを試みるダメなら0を返す
{
	if (check_vertically(arr, x, n) == 1 && check_horizontally(arr, y, n) == 1 && check_mass(arr, x, y, n) == 1)
	{
		return arr[y][x] = n;
	}
	else
	{
		return 0;
	}
}

bool solve_sudoku(vector<vector<int>> &arr, int x, int y)
// x:0~8、横方向,y:0~8、縦方向
// 深さ優先探索
{
	if (y > 8)
	{
		return true;
	}
	else if (x > 8)
	{
		if (solve_sudoku(arr, 0, y + 1) == 1)
		{
			return true;
		}
	}
	else if (arr[y][x] != 0)
	{
		if (solve_sudoku(arr, x + 1, y) == 1)
		{
			return true;
		}
	}
	else
	{
		for (int i = 1; i <= 9; ++i)
		{
			int tmp = change_num(arr, x, y, i);
			if (tmp != 0)
			{
				if (solve_sudoku(arr, x + 1, y) == 1)
				{
					return true;
				}
			}
		}
		arr[y][x] = 0;
	}
	return false;
}
