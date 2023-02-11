#include <bits/stdc++.h>
using namespace std;
int N;
char board[65][65];
string ans;
void partition(int x_f, int x_l, int y_f, int y_l)
{
    bool b = false;
    char first = board[y_f][x_f];
    for (int i = y_f; i < y_l; i++)
    {
        for (int j = x_f; j < x_l; j++)
        {
            if (b)
                break;
            else if (board[i][j] != first)
                b = true;
        }
    }
    if (!b)
    {
        ans += first;
        return;
    }
    ans += "(";
    first = board[y_f][x_f];
    int mid_y = (y_f + y_l) / 2;
    int mid_x = (x_f + x_l) / 2;
    b = false;
    for (int i = y_f; i < mid_y; i++)
    {
        for (int j = x_f; j < mid_x; j++)
        {
            if (b)
                break;
            else if (board[i][j] != first)
            {
                b = true;
                partition(x_f, mid_x, y_f, mid_y);
            }
        }
        if (b)
            break;
    }
    if (!b)
        ans += first;
    b = false;
    first = board[y_f][mid_x];
    for (int i = y_f; i < mid_y; i++)
    {
        for (int j = mid_x; j < x_l; j++)
        {
            if (b)
                break;
            else if (board[i][j] != first)
            {
                b = true;
                partition(mid_x, x_l, y_f, mid_y);
            }
        }
        if (b)
            break;
    }
    if (!b)
        ans += first;
    b = false;
    first = board[mid_y][x_f];
    for (int i = mid_y; i < y_l; i++)
    {
        for (int j = x_f; j < mid_x; j++)
        {
            if (b)
                break;
            else if (board[i][j] != first)
            {
                b = true;
                partition(x_f, mid_x, mid_y, y_l);
            }
        }
        if (b)
            break;
    }
    if (!b)
        ans += first;
    b = false;
    first = board[mid_y][mid_x];
    for (int i = mid_y; i < y_l; i++)
    {
        for (int j = mid_x; j < x_l; j++)
        {
            if (b)
                break;
            else if (board[i][j] != first)
            {
                b = true;
                partition(mid_x, x_l, mid_y, y_l);
            }
        }
        if (b)
            break;
    }
    if (!b)
        ans += first;
    ans += ")";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    ans = "";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    partition(0, N, 0, N);
    cout << ans << '\n';
    return 0;
}