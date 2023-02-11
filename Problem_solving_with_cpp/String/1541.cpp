#include <bits/stdc++.h>
using namespace std;
string str;
vector<char> ch;
vector<int> n;
int ans;
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> str;
    int Size = str.size();
    int x = 1;
    int num = 0;
    for (int i = Size - 1; i >= 0; i--)
    {
        if (str[i] == '-' || str[i] == '+')
        {
            ch.push_back(str[i]);
            n.push_back(num);
            num = 0;
            x = 1;
        }
        else
        {
            num += (str[i] - '0') * x;
            x *= 10;
        }
    }
    n.push_back(num);
    Size = n.size();
    ans = n[Size - 1];
    num = 0;
    for (int i = Size - 2; i >= 0; i--)
    {
        if (ch[i] == '-')
        {
            if (num)
            {
                ans -= num;
                num = n[i];
            }
            else
                num = n[i];
        }
        else if (num)
        {
            num += n[i];
        }
        else
            ans += n[i];
    }
    ans -= num;
    cout << ans << '\n';

    return 0;
}