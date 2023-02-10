#include <bits/stdc++.h>
using namespace std;
int prime[1000001];
int n;
vector<int> v;
void prime_make()
{
    for (int i = 2; i <= 1000000; i++)
        prime[i] = i;
    for (int i = 2; i <= 1000000; i++)
    {
        if (!prime[i])
            continue;
        for (int j = 2 * i; j <= 1000000; j += i)
            prime[j] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    prime_make();
    for (int i = 3; i <= 1000000; i += 2)
        if (prime[i])
            v.push_back(prime[i]);
    while (1)
    {
        cin >> n;
        if (!n)
            break;
        else
        {
            int Size = v.size() - 1;
            int left = 0;
            int right = Size;
            while (left < right)
            {
                int mid = (left + right + 1) / 2;
                if (v[mid] < n)
                    left = mid;
                else
                    right = mid - 1;
            }
            int a = 0;
            int b = left;
            while (a < b)
            {
                if (v[a] + v[b] == n)
                    break;
                else if (v[a] + v[b] < n)
                    a++;
                else
                    b--;
            }
            cout << n << " = " << v[a] << " + " << v[b] << '\n';
        }
    }
    return 0;
}