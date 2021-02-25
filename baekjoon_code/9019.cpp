#include<bits/stdc++.h>

using namespace std;

string vis[10000];
queue<int> qu;
int is_valid(int x)
{
	if (!vis[x].empty()) return false;
	return true;
}

int turn_R(int x)
{
	int ex[4];
	for (int i = 3; i >= 0; i--)
	{
		ex[i] = x % 10;
		x /= 10;
	}
	int el = 0;
	for (int i = 0; i < 4; i++)
	{
		el *= 10;
		el += ex[(i + 3) % 4];
	}
	return el;
}
int turn_L(int x)
{
	int ex[4];
	for (int i = 3; i >= 0; i--)
	{
		ex[i] = x % 10;
		x /= 10;
	}
	int el = 0;
	for (int i = 0; i < 4; i++)
	{
		el *= 10;
		el += ex[(i + 1) % 4];
	}
	return el;
}


void push_qu(int x, char f, int n)
{
	int el = x;
	if (el == -1) el = 9999;
	if (el > 9999) el = el % 10000;
	if (is_valid(el))
	{
		qu.push(el);
		vis[el] = vis[n] + f;
	}
}


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int A, B;
		cin >> A >> B;
		qu.push(A);
		vis[A] = 'H';
		while (!qu.empty())
		{
			int el = qu.front();
			qu.pop();
			int in;
			in = el - 1;
			push_qu(el - 1, 'S', el);
			if (in == B)
			{
				string an = vis[in].substr(1);
				cout << an << endl;
				break;
			}
			in = el * 2;
			push_qu(in, 'D', el);
			if (in == B)
			{
				string an = vis[in].substr(1);
				cout << an << endl;
				break;
			}
			in = turn_R(el);
			push_qu(in, 'R', el);
			if (in == B)
			{
				string an = vis[in].substr(1);
				cout << an << endl;
				break;
			}
			in = turn_L(el);
			push_qu(in, 'L', el);
			if (in == B)
			{
				string an = vis[in].substr(1);
				cout << an << endl;
				break;
			}
		}
		for (int i = 0; i < 10000; i++) vis[i].clear();
		while (!qu.empty()) qu.pop();
	}
	return 0;
}
