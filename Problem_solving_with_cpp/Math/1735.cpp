#include <bits/stdc++.h>
using namespace std;
int A, B;
int C, D;
int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B;
    cin >> C >> D;
    int son = B * C + D * A;
    int mother = B * D;
    int GCD;
    if (son > mother)
        GCD = gcd(son, mother);
    else
        GCD = gcd(mother, son);
    cout << son / GCD << ' ' << mother / GCD << '\n';
    return 0;
}