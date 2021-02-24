#include<bits/stdc++.h>

using namespace std;


int main()
{
	int N, M;
	cin >> N >> M;
	string st;
	cin >> st;
	int an = 0;
	for (int i = 0; i < st.size(); i++)
	{
		int cnt = 0;
		while (st[i] == 'I' && st[i + 1] == 'O' && st[i + 2] == 'I')
		{
			cnt++;
			i += 2;
		}
		if (cnt >= N) an += cnt - N + 1;
	}
	cout << an;
	return 0;
}