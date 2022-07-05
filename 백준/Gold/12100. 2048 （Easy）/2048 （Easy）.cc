#include <bits/stdc++.h>


using namespace std;
int n;
int board[20][20];
int before_board[20][20];

void copy_board()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			before_board[i][j] = board[i][j];
	}
}

void move_up()
{
	int T = n;
	while (T--)
	{
		for (int i = 0; i < n-1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = board[i+1][j];
					board[i+1][j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == board[i + 1][j])
			{
				board[i][j] *= 2;
				board[i + 1][j] = 0;
			}
		}
	}
	T = n;
	while (T--)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = board[i + 1][j];
					board[i + 1][j] = 0;
				}
			}
		}
	}
}
void move_down()
{
	int T = n;
	while (T--)
	{
		for (int i = n-1; i >= 1; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = board[i - 1][j];
					board[i - 1][j] = 0;
				}
			}
		}
	}
	for (int i = n-1; i >=1; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == board[i - 1][j])
			{
				board[i][j] *= 2;
				board[i - 1][j] = 0;
			}
		}
	}
	T = n;
	while (T--)
	{
		for (int i = n - 1; i >= 1; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = board[i - 1][j];
					board[i - 1][j] = 0;
				}
			}
		}
	}
}
void move_left()
{
	int T = n;
	while (T--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = board[i][j + 1];
					board[i][j + 1] = 0;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if (board[i][j] == board[i][j+1])
			{
				board[i][j] *= 2;
				board[i][j+1] = 0;
			}
		}
	}

	T = n;
	while (T--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = board[i][j + 1];
					board[i][j + 1] = 0;
				}
			}
		}
	}
}
void move_right()
{
	int T = n;
	while (T--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n-1; j >= 1; j--)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = board[i][j - 1];
					board[i][j - 1] = 0;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for(int j=n-1;j>=1;j--)
		{
			if (board[i][j] == board[i][j-1])
			{
				board[i][j] *= 2;
				board[i][j-1] = 0;
			}
		}
	}

	T = n;
	while (T--)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j >= 1; j--)
			{
				if (board[i][j] == 0)
				{
					board[i][j] = board[i][j - 1];
					board[i][j - 1] = 0;
				}
			}
		}
	}

}
int move_board(int a)
{
	if (a == 5)
	{
		int max_num = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				max_num = max(max_num, board[i][j]);
			}
		}
		return max_num;
	}
	int bef_board[20][20];
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			bef_board[i][j] = board[i][j];
		}
	}
	int num[4];
	move_up();
	num[0] = move_board(a + 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = bef_board[i][j];
		}
	}
	move_down();
	num[1] = move_board(a + 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = bef_board[i][j];
		}
	}
	move_right();
	num[2] = move_board(a + 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = bef_board[i][j];
		}
	}
	move_left();
	num[3] = move_board(a + 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = bef_board[i][j];
		}
	}

	return max(max(num[0], num[1]), max(num[2], num[3]));
}
int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	cout << move_board(0);
	return 0;
}