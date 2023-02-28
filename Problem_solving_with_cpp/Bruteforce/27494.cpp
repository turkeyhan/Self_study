#include <bits/stdc++.h>
using namespace std;
int N, cnt;
bool check(int num)
{
    int cur = 0;
    while (num > 0)
    {
        if (num % 10 == 3 && !cur)
            cur++;
        else if (num % 10 == 2 && cur == 1)
            cur++;
        else if (num % 10 == 0 && cur == 2)
            cur++;
        else if (num % 10 == 2 && cur == 3)
            cur++;
        num /= 10;
    }
    if (cur == 4)
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        if (check(i))
            cnt++;
    cout << cnt << '\n';
    return 0;
}
