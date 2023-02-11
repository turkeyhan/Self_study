#include <bits/stdc++.h>
using namespace std;
int N, M, nx, ny;
int board[301][301];
int dp[301][301];
int visited[301][301];
int ans;
int nnx[2] = {1, 0};
int nny[2] = {0, 1};

bool in_board(int x, int y)
{
    return (0 <= x && x <= 300 && 0 <= y && y <= 300);
}
void solve()
{
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (1)
    {
        int Size = q.size();
        M--;
        if (!Size || !M)
            break;
        for (int j = 0; j < Size; j++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 2; i++)
            {
                int xx = x + nnx[i];
                int yy = y + nny[i];
                if (in_board(xx, yy))
                {
                    if (board[xx][yy])
                    {
                        if (dp[x][y] + M > dp[xx][yy])
                            dp[xx][yy] = dp[x][y] + M;
                    }
                    else if (dp[x][y] > dp[xx][yy])
                        dp[xx][yy] = dp[x][y];
                    if (!visited[xx][yy])
                    {
                        q.push({xx, yy});
                        visited[xx][yy] = 1;
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> nx >> ny;
        board[nx][ny] = 1;
    }
    solve();
    for (int i = 0; i < 301; i++)
    {
        for (int j = 0; j < 301; j++)
        {
            if (ans < dp[i][j])
                ans = dp[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}