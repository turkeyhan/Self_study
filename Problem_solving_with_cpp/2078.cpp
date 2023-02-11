#include <bits/stdc++.h>
using namespace std;
int A, B;
int ans_l, ans_r;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B;
    while (!(A == 1 && B == 1))
    {
        if (A == 1)
        {
            ans_r += (B - 1);
            B -= (B - 1);
        }
        else if (B == 1)
        {
            ans_l += (A - 1);
            A -= (A - 1);
        }
        else if (A > B)
        {
            A -= B;
            ans_l++;
        }
        else if (B > A)
        {
            B -= A;
            ans_r++;
        }
    }
    cout << ans_l << ' ' << ans_r << '\n';
    return 0;
}