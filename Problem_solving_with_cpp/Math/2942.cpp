#include <bits/stdc++.h>
using namespace std;
int R, G;
vector<int> ans;
int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
void add_divisors(int num)
{
    for (int i = 1; i * i <= num; i++)
    {
        if (!(num % i))
        {
            ans.push_back(i);
            if (num / i != i)
                ans.push_back(num / i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> G;
    int GCD;
    if (R > G)
        GCD = gcd(R, G);
    else
        GCD = gcd(G, R);
    add_divisors(GCD);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ' << R / ans[i] << ' ' << G / ans[i] << '\n';

    return 0;
}