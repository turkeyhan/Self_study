#include <bits/stdc++.h>
using namespace std;
int A, K;
int dp[2002000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> K;
    for (int i = A; i <= K; i++) dp[i] = 1e9;
    dp[A] = 0;
    dp[A + 1] = 1;
    dp[A * 2] = 1;
    for (int i = A; i <= K; i++)
    {
        if (dp[i])
        {
            dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
            dp[i * 2] = min(dp[i] + 1, dp[i * 2]);
        }
    }
    cout << dp[K] << '\n';
    return 0;
}