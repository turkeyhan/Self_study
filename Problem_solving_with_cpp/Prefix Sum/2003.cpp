#include <bits/stdc++.h>
using namespace std;
int N, M;
int tmp;
int ans;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int i = 0;
    int j = 0;
    int Sum = v[i];
    if (Sum == M)
        ans++;
    while (!(i == N - 1 && j == N - 1))
    {
        if (Sum >= M)
        {
            Sum -= v[i];
            i++;
            if (i > j)
            {
                j++;
                Sum += v[j];
            }
        }
        else
        {
            if (j == N - 1)
                break;
            else
            {
                j++;
                Sum += v[j];
            }
        }
        if (Sum == M)
            ans++;
    }

    cout << ans << '\n';
    return 0;
}