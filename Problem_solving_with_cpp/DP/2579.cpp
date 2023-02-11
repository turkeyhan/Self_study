#include <bits/stdc++.h>
using namespace std;
int N;
int dp[301][3];
int arr[301];
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cin >> arr[0];
    dp[0][1] = arr[0];
    for (int i = 1; i < N; i++)
    {
        cin >> arr[i];
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][2] = dp[i - 1][1] + arr[i];
    }
    cout << max(dp[N - 1][1], dp[N - 1][2]) << '\n';
    return 0;
}