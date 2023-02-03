#include <bits/stdc++.h>
using namespace std;
int T, K;
int sum;
int arr[1001];
vector<int> v;
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 50; i++)
    {
        sum += i;
        v.push_back(sum);
    }
    int Size = v.size();
    sum = 0;
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            for (int k = 0; k < Size; k++)
            {
                sum = v[i] + v[j] + v[k];
                if (sum <= 1000)
                    arr[sum] = 1;
            }
        }
    }
    cin >> T;
    while (T--)
    {
        cin >> K;
        if (arr[K])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}