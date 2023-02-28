#include <bits/stdc++.h>
using namespace std;
string board[10][10];
vector<string> v;
map<string, vector<string>> m;
int xx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int yy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    for (int i = 1; i < 9; i += 3)
    {
        for (int j = 1; j < 9; j += 3)
        {
            if (i == 4 && j == 4)
                continue;
            v.push_back(board[i][j]);
            for (int k = 0; k < 8; k++)
                m[board[i][j]].push_back(board[i + yy[k]][j + xx[k]]);
            sort(m[board[i][j]].begin(), m[board[i][j]].end());
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!j)
                cout << '#' << i + 1 << ". " << v[i] << '\n';
            else
                cout << '#' << i + 1 << '-' << j << ". " << m[v[i]][j - 1] << '\n';
        }
    }
    return 0;
}
