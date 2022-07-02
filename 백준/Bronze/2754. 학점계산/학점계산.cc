#include<bits/stdc++.h>
using namespace std;




int main()
{
	string a;
	cin >> a;
	double num;
	if (a[0] == 'A')
	{
		num = 4.0;
	}
	else if (a[0] == 'B')
	{
		num = 3.0;
	}
	else if (a[0] == 'C')
	{
		num = 2.0;
	}
	else if (a[0] == 'D')
	{
		num = 1.0;
	}
	else num = 0;
	if (a[1] == '+')
	{
		num += 0.3;
	}
	else if (a[1] == '-')
	{
		num -= 0.3;
	}
	cout << fixed;
	cout.precision(1);
	cout << num;
	return 0;
}