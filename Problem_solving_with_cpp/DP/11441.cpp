#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[100100];
int I, J;
int dp[100100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= N; i++)
        dp[i] = dp[i - 1] + arr[i];
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> I >> J;
        cout << dp[J] - dp[I - 1] << '\n';
    }
    return 0;
}
