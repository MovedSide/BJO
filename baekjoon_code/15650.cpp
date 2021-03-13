#include<bits/stdc++.h>

using namespace std;

int a, b;


void func(int x, int cnt, string st)
{
    if (cnt == b)
    {
        for (char a : st)
        {
            cout << a << " ";
        }
        cout << "\n";
        return;
    }
    if (x > a) return;

    string st1 = st;
    st1 += x + '0';
    string st2 = st;
    func(x + 1, cnt + 1, st1);
    func(x + 1, cnt, st2);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> a >> b;
    string st;
    func(1, 0, st);
    return 0;
}