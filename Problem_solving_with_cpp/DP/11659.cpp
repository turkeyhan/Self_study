#include <bits/stdc++.h>
using namespace std;
int N, M, i, j, tmp;
int dp[100001];
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int k = 1; k <= N; k++)
    {
        if (k == 1)
            cin >> dp[k];
        else
        {
            cin >> dp[k];
            dp[k] = dp[k - 1] + dp[k];
        }
    }
    for (int k = 1; k <= M; k++)
    {
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << '\n';
    }
    return 0;
}