#include<bits/stdc++.h>

using namespace std;



int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string st[30];
		int cln[30] = { 0,};
		int index = 0;
		while (n--)
		{
			string inp1, inp2;
			cin >> inp1 >> inp2;
			int i;
			for (i = 0; i < index; i++)
			{
				if (inp2 == st[i]) break;
			}
			if (i != index)
			{
				cln[i]++;
			}
			else
			{
				st[index] = inp2;
				cln[index]++;
				index++;
			}
		}
		int an = 1;
		for (int i = 0; i < index; i++) an *= cln[i]+1;
		cout << an-1 << endl;


	}
	return 0;
}
