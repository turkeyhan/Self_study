#include <bits/stdc++.h>
using namespace std;
int N;
bool b;
string ans;
bool check(string str)
{
    int Size = str.size();
    for (int i = 0; i < Size; i++)
    {
        int len = (Size - i) / 2;
        string cmp1 = str.substr(i, len);
        string cmp2 = str.substr(i + len, Size - (i + len));
        if (cmp1 == cmp2)
            return false;
    }
    return true;
}
void good(int cnt, string s)
{
    if (b || !check(s))
        return;
    if (cnt == N)
    {
        b = true;
        ans = s;
        return;
    }
    else
    {
        good(cnt + 1, s + "1");
        good(cnt + 1, s + "2");
        good(cnt + 1, s + "3");
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    b = false;
    cin >> N;
    good(0, "");
    cout << ans << '\n';
    return 0;
}