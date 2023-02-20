#include <bits/stdc++.h>
using namespace std;
int board[101];
int visited[101];
map<int, int> warp;
int x, y, u, v;
int N, M;
int ans;
void solve(int start)
{
    visited[start] = 1;
    queue<int> q;
    q.push(start);

    while (1)
    {
        int Size = q.size();
        if (!Size)
            break;
        for (int i = 0; i < Size; i++)
        {
            int cur = q.front();
            q.pop();
            if (board[cur])
            {
                cur = warp[cur];
                visited[cur] = 1;
            }
            for (int j = 1; j <= 6; j++)
            {
                int next = cur + j;
                if (next == 100)
                {
                    ans++;
                    return;
                }
                else if (next > 100)
                    continue;
                else if (!visited[next])
                {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
        ans++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        board[x] = 1;
        warp[x] = y;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        board[u] = -1;
        warp[u] = v;
    }
    solve(1);
    cout << ans << '\n';
    return 0;
}