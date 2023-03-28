#include <bits/stdc++.h>
using namespace std;
int R, C;
char board[51][51];
int xx[4] = { 1, 0, -1, 0 };
int yy[4] = { 0, 1, 0, -1 };
typedef struct node {
    int y;
    int x;
    char c;
}node;
bool in_board(int y, int x)
{
    return (0 <= x && x < C && 0 <= y && y < R);
}
int bfs(pair<int, int> start)
{
    queue <node> q;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (board[i][j] == '*') q.push({ i, j, '*' });
    q.push({ start.first, start.second, 'S' });
    int cnt = 0;
    while (1)
    {
        cnt++;
        int qs = q.size();
        if (!qs) break;
        for (int i = 0; i < qs; i++)
        {
            node qtmp = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int ny = qtmp.y + yy[j];
                int nx = qtmp.x + xx[j];
                if (in_board(ny, nx))
                {
                    if (board[ny][nx] == '.')
                    {
                        if (qtmp.c == '*')
                        {
                            board[ny][nx] = '*';
                            q.push({ ny, nx, '*' });
                        }
                        else
                        {
                            board[ny][nx] = 'S';
                            q.push({ ny, nx, 'S' });
                        }
                    }
                    else if (qtmp.c == 'S' && board[ny][nx] == 'D') return cnt;
                }
            }
        }

    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    pair<int, int> start;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S') start = { i, j };
        }
    }

    int ans = bfs(start);
    if (!ans) cout << "KAKTUS" << '\n';
    else cout << ans << '\n';
    return 0;
}