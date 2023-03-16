#include <bits/stdc++.h>
using namespace std;
int N;
int rec;
int num;
int cnt;
pair<int, int> arr[101];
int Min;
int Min_num;
int Min_cnt;
int N_;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> rec;
    while (rec--)
    {
        cin >> num;
        Min_num = 0;
        if (arr[num].first)
            arr[num].first++;
        else
        {
            cnt++;
            N_++;
            if (N_ > N)
            {
                for (int i = 1; i <= 100; i++)
                {
                    if (arr[i].first)
                    {
                        if (!Min_num)
                        {
                            Min = arr[i].first;
                            Min_num = i;
                            Min_cnt = arr[i].second;
                        }
                        else
                        {
                            if (Min > arr[i].first)
                            {
                                Min = arr[i].first;
                                Min_num = i;
                                Min_cnt = arr[i].second;
                            }
                            else if (Min == arr[i].first && Min_cnt > arr[i].second)
                            {
                                Min = arr[i].first;
                                Min_num = i;
                                Min_cnt = arr[i].second;
                            }
                        }
                    }
                }
                arr[Min_num].first = 0;
            }
            arr[num].first = 1;
            arr[num].second = cnt;
        }
    }
    for (int i = 1; i <= 100; i++)
    {
        if (arr[i].first)
            cout << i << ' ';
    }
    cout << '\n';
    return 0;
}