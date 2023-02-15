#include <bits/stdc++.h>
using namespace std;

int n;
char Map[101][101];
bool visited[101][101];
int normalCnt, rgCnt;

void normalDFS(int y, int x, char color)
{
    visited[y][x] = true;

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        if (visited[ny][nx] || Map[ny][nx] != color)
            continue;

        normalDFS(ny, nx, color);
    }
}

void rgDFS(int y, int x, char color)
{
    visited[y][x] = true;

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        if (visited[ny][nx])
            continue;

        if (color == 'B')
        {
            if (Map[ny][nx] == 'B')
                rgDFS(ny, nx, color);
        }
        else
        {
            if (Map[ny][nx] != 'B')
                rgDFS(ny, nx, color);
        }
    }
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> Map[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                normalDFS(i, j, Map[i][j]);
                normalCnt++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                rgDFS(i, j, Map[i][j]);
                rgCnt++;
            }
        }
    }

    cout << normalCnt << " " << rgCnt << "\n";

    return 0;
}