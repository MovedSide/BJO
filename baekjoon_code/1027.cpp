#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* bu = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> bu[i];
    }
    int max1 = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int max2 = -1;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            double x = (1.0)*(bu[j] - bu[i]) / (j - i);
            int cal = bu[min(i,j)];
            bool can_see = true;            
            for (int k = min(i,j)+1; k < max(i,j); k++)
            {
                double cal2 = cal + x*(k-min(i,j));
                if (bu[k] >= cal2)
                {
                    can_see = false;
                    break;
                }
            }
            if (can_see == true) cnt++;
        }
        if (max1 < cnt) max1 = cnt;
    }
    cout << max1;
    return 0;
}