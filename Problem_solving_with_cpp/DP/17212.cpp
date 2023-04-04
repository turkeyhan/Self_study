#include <bits/stdc++.h>
using namespace std;
int N, ans;
int dp[100100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) dp[i] = 100100;
    for (int i = 0; i <= N; i++)
    {
        dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
        dp[i + 2] = min(dp[i] + 1, dp[i + 2]);
        dp[i + 5] = min(dp[i] + 1, dp[i + 5]);
        dp[i + 7] = min(dp[i] + 1, dp[i + 7]);
    }
    cout << dp[N] << '\n';
    return 0;
}