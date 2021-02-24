#include<bits/stdc++.h>

using namespace std;

int T;

int main()
{
	cin >> T;
	while (T--)
	{
		string inp;
		string fuc;
		int n;
		cin >> fuc;
		cin >> n;
		cin >> inp;
		deque<int> num;
		string tmp;
		for (int i = 0; i < inp.size(); i++)
		{
			if (inp[i] >= '0' && inp[i] <= '9')
			{
				tmp += inp[i];
			}
			else if (inp[i] == ',' || inp[i] == ']')
			{
				if (!tmp.empty())
				{
					num.push_back(stoi(tmp));
					tmp.clear();
				}
			}
		}
		bool is_error = false;
		bool is_reverse = false;
		for (int i = 0; i < fuc.length(); i++)
		{
			if (fuc[i] == 'R')
			{
				is_reverse = !is_reverse;
			}
			else if (fuc[i] == 'D')
			{
				if (num.empty())
				{
					is_error = true;
					cout << "error\n";
					break;
				}
				else
				{
					if (!is_reverse) num.pop_front();
					else num.pop_back();
				}
			}
		}
		if (!is_error)
		{
			if (!is_reverse)
			{
				cout << "[";
				while (!num.empty())
				{
					cout << num.front();
					num.pop_front();
					if (!num.empty()) cout << ",";
				}
				printf("]\n");
			}
			else
			{
				cout << "[";
				while (!num.empty())
				{
					cout << num.back();
					num.pop_back();
					if (!num.empty()) cout << ",";
				}
				printf("]\n");
			}
		}
	}
	return 0;
}