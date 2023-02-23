#include <bits/stdc++.h>
using namespace std;
int N, M, x_1, y_1, x_2, y_2;
int board[1025][1025];
long long sum[1025][1025];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];

    for (int i = 1; i <= N; i++)
    {
        long long row[1025] = {0};
        for (int j = 1; j <= N; j++)
        {
            row[j] = row[j - 1] + board[i][j];
            sum[i][j] = sum[i - 1][j] + row[j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        long long ans = sum[x_2][y_2] - sum[x_2][y_1 - 1] - sum[x_1 - 1][y_2] + sum[x_1 - 1][y_1 - 1];
        cout << ans << '\n';
    }
    return 0;
}