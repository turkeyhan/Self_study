#include <bits/stdc++.h>
using namespace std;
int T, n;
string str1, str2;
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        map<string, int> m;
        vector<string> p;
        cin >> n;
        while (n--)
        {
            cin >> str1 >> str2;
            if (m.count(str2) == 1)
                m[str2]++;
            else
            {
                m[str2] = 2;
                p.push_back(str2);
            }
        }
        int ans = 1;
        for (int i = 0; i < p.size(); i++)
            ans *= m[p[i]];
        cout << ans - 1 << '\n';
    }
    return 0;
}