#include <bits/stdc++.h>
using namespace std;
int N, opr;
char ch;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    deque<pair<char, int>> d;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> opr;
        if (opr == 1)
        {
            cin >> ch;
            cnt++;
            d.push_back({ch, cnt});
        }
        else if (opr == 2)
        {
            cin >> ch;
            cnt++;
            d.push_front({ch, cnt});
        }
        else
        {
            if (d.empty())
                continue;
            if (d.front().second < d.back().second)
            {
                d.pop_back();
                cnt--;
            }
            else
            {
                d.pop_front();
                cnt--;
            }
        }
    }
    if (d.empty())
        cout << 0 << '\n';
    else
    {
        while (!d.empty())
        {
            cout << d.front().first;
            d.pop_front();
        }
        cout << '\n';
    }
    return 0;
}
