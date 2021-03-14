#include<bits/stdc++.h>

using namespace std;

int N, M;

void func(int x, int cnt,string st)
{
    if (cnt == M)
    {
        for (char a : st)
            cout << a << " ";
        cout << "\n";
        return;
    }
    if (x > N) return;
    string st1 = st;
    st1 += x + '0';
    string st2 = st;
    func(x, cnt + 1, st1);
    func(x + 1, cnt, st2);
}




int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    string st;
    func(1, 0, st);
    return 0;
}