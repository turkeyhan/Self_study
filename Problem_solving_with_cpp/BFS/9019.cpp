#include <bits/stdc++.h>
using namespace std;
int T;
int A, B;
int check[10001];
int ten[4];
int LL(int num)
{
    int ar[4]{0};
    int j = 3;
    int res = 0;
    while (num)
    {
        ar[j] = num % 10;
        num /= 10;
        j--;
    }
    for (int i = 0; i < 3; i++)
        swap(ar[i], ar[i + 1]);
    for (int i = 0; i < 4; i++)
        res += (ar[i] * ten[i]);
    return res;
}
int RR(int num)
{
    int ar[4]{0};
    int j = 3;
    int res = 0;
    while (num)
    {
        ar[j] = num % 10;
        num /= 10;
        j--;
    }
    for (int i = 3; i > 0; i--)
        swap(ar[i], ar[i - 1]);
    for (int i = 0; i < 4; i++)
        res += (ar[i] * ten[i]);
    return res;
}
string solve()
{
    queue<pair<string, int>> q;
    q.push({"", A});
    check[A] = 1;
    while (!q.empty())
    {
        string opt = q.front().first;
        int num = q.front().second;
        q.pop();
        if (num == B)
            return opt;
        // D
        int tmp = num * 2;
        if (tmp > 9999)
            tmp %= 10000;
        if (!check[tmp])
        {
            q.push({opt + "D", tmp});
            check[tmp] = 1;
        }
        // S
        tmp = num - 1;
        if (!num)
            tmp = 9999;
        if (!check[tmp])
        {
            q.push({opt + "S", tmp});
            check[tmp] = 1;
        }
        // L
        tmp = LL(num);
        if (!check[tmp])
        {
            q.push({opt + "L", tmp});
            check[tmp] = 1;
        }
        // R
        tmp = RR(num);
        if (!check[tmp])
        {
            q.push({opt + "R", tmp});
            check[tmp] = 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    ten[0] = 1000;
    ten[1] = 100;
    ten[2] = 10;
    ten[3] = 1;
    while (T--)
    {
        cin >> A >> B;
        string ans = solve();
        cout << ans << '\n';
        for (int i = 0; i <= 10000; i++)
            check[i] = 0;
    }

    return 0;
}