#include <bits/stdc++.h>
using namespace std;
int N, M;
map<string, string> memo;
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    while (N--)
    {
        string adr, psw;
        cin >> adr >> psw;
        memo[adr] = psw;
    }
    while (M--)
    {
        string fd;
        cin >> fd;
        cout << memo[fd] << '\n';
    }
    return 0;
}