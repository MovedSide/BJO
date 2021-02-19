#include<bits/stdc++.h>

using namespace std;
string st;


int main()
{

	cin >> st;
	int num = 0;
	bool is_minus = false;
	int sum = 0;
	for (auto li = st.begin(); li < st.end(); li++)
	{
		if (*li >= '0' && *li <= '9')
		{
			num *= 10;
			num += *li - '0';
		}
		else if (*li == '+')
		{
			if (is_minus) sum -= num;
			else sum += num;
			num = 0;
		}
		else if (*li == '-')
		{
			if (!is_minus)
			{
				sum += num;
				is_minus = true;
			}
			else
			{
				sum -= num;
			}
			num = 0;
		}
	}
	if (is_minus) sum -= num;
	else sum += num;
	cout << sum;
	return 0;
}