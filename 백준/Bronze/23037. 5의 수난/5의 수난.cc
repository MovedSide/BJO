#include<bits/stdc++.h>
using namespace std;




int main()
{
	int n;
	int an=0;
	cin >> n;
	for (int i = 0; i < 5; i++)
	{
		int num = n % 10;
		num = num * num * num * num * num;
		an += num;
		n /= 10;
	}
	cout << an;
	return 0;
}