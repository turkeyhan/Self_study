#include <bits/stdc++.h>
using namespace std;
int N, M;
int num;
int cnt;
int arr[51];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cur = 1;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        arr[i] = 1;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        while (!arr[cur])
        {
            cur++;
            if (cur > N)
                cur -= N;
        }
        if (cur == num)
        {
            arr[cur] = 0;
            cur++;
            if (cur > N)
                cur -= N;
            continue;
        }
        int a = cur;
        int b = cur;
        int ct = 0;
        while (1)
        {
            ct++;
            a++;
            b--;
            if (a > N)
                a -= N;
            if (b < 1)
                b += N;
            while (!arr[a])
            {
                a++;
                if (a > N)
                    a -= N;
            }
            while (!arr[b])
            {
                b--;
                if (b < 1)
                    b += N;
            }
            if (a == num)
            {
                arr[a] = 0;
                cnt += ct;
                cur = a + 1;
                if (cur > N)
                    cur -= N;
                break;
            }
            if (b == num)
            {
                arr[b] = 0;
                cnt += ct;
                cur = b + 1;
                if (cur > N)
                    cur -= N;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
