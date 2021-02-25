#include<bits/stdc++.h>

using namespace std;


bool vis[1000000] = { false, };


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int k;
		cin >> k;
		priority_queue<pair<int, int>> maxh;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
		int index = 0;
		for (int i = 0; i < k; i++)
		{
			int el;
			char func;
			cin >> func >> el;
			if (func == 'I')
			{
				maxh.push(make_pair(el, index));
				minh.push(make_pair(el, index));
				vis[index] = true;
				index++;
			}
			else if (func == 'D')
			{
				if (el == 1)
				{
					while (!maxh.empty() && !vis[maxh.top().second])
					{
						maxh.pop();
					}
					if (!maxh.empty())
					{
						vis[maxh.top().second] = false;
						maxh.pop();
					}
				}
				else if (el == -1)
				{
					while (!minh.empty() && !vis[minh.top().second])
					{
						minh.pop();
					}
					if (!minh.empty())
					{
						vis[minh.top().second] = false;
						minh.pop();
					}
				}
			}
		}
		while (!maxh.empty() && !vis[maxh.top().second]) maxh.pop();
		while (!minh.empty() && !vis[minh.top().second]) minh.pop();
		if (maxh.empty() || minh.empty()) cout << "EMPTY" << endl;
		else cout << maxh.top().first << " " << minh.top().first << endl;
	}
	return 0;
}
