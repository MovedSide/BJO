#include<bits/stdc++.h>
using namespace std;




int main()
{
	string a;
	cin >> a;
	for (char c : a)
	{
		char an;
		if (c >= 'a')  an =  c - ('a' - 'A');
		else an = c + ('a' - 'A');
		cout << an;
	}
	return 0;
}