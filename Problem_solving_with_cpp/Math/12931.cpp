#include <bits/stdc++.h>
using namespace std;
int N;
int arr_B[51];
int cnt;
int zero;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr_B[i];
        if (!arr_B[i])
            zero++;
    }
    while (1)
    {
        if (zero == N)
            break;
        for (int i = 0; i < N; i++)
        {
            if (!arr_B[i])
                continue;
            else if (arr_B[i] % 2)
            {
                arr_B[i]--;
                if (!arr_B[i])
                    zero++;
                cnt++;
            }
        }
        if (zero == N)
            break;
        for (int i = 0; i < N; i++)
            arr_B[i] /= 2;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}