#include <bits/stdc++.h>
using namespace std;
int M, N, H;
int board[101][101][101];
int visited[101][101][101];
int cnt, Time;
int xx[6] = {1, 0, -1, 0, 0, 0};
int yy[6] = {0, -1, 0, 1, 0, 0};
int zz[6] = {0, 0, 0, 0, 1, -1};
typedef struct node
{
    int z;
    int y;
    int x;
} node;
bool in_board(int z, int y, int x)
{
    return (0 <= x && x < M && 0 <= y && y < N && 0 <= z && z < H);
}
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    queue<node> q;
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> board[i][j][k];
                if (!board[i][j][k])
                    cnt++;
                else if (board[i][j][k] == 1)
                {
                    visited[i][j][k] = 1;
                    q.push({i, j, k});
                }
            }
        }
    }
    while (1)
    {
        int Size = q.size();
        if (!Size)
            break;
        for (int i = 0; i < Size; i++)
        {
            int z = q.front().z;
            int y = q.front().y;
            int x = q.front().x;
            q.pop();
            for (int j = 0; j < 6; j++)
            {
                int nx = x + xx[j];
                int ny = y + yy[j];
                int nz = z + zz[j];
                if (in_board(nz, ny, nx) && !board[nz][ny][nx] && !visited[nz][ny][nx])
                {
                    cnt--;
                    visited[nz][ny][nx] = 1;
                    board[nz][ny][nx] = 1;
                    q.push({nz, ny, nx});
                }
            }
        }
        Time++;
    }

    if (cnt)
        cout << -1 << '\n';
    else
        cout << Time - 1 << '\n';

    return 0;
}