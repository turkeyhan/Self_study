// 알고리즘(algorithm): 분할 정복(divide and conquer)
// 난이도(level): normal
// 틀린 횟수(wrong count): 1(time over)
// 틀린 이유(wrong reason): 분할 정복인데 브루트 포스급으로 진행.
//                          수학적 조건 추가로 시간 줄임.
// 핵심(point): r과 c의 범위에 들어가는 것을 순서에 따라 확인 후 카운트 올리고 재귀 호출
#include <bits/stdc++.h>
using namespace std;
int N, r, c;
int ans;
int xx[4] = {0, 1, 0, 1};
int yy[4] = {0, 0, 1, 1};
void Partition(int x, int y, int num)
{
    if (num == 2)
    {
        if (y <= r && r <= y + 1 && x <= c && c <= x + 1)
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = x + xx[i];
                int ny = y + yy[i];
                if (nx == c && ny == r)
                {
                    ans++;
                    cout << ans - 1 << '\n';
                    exit(0);
                }
                else
                    ans++;
            }
        }
        else
            ans += 4;
    }
    else
    {
        // 2, 4
        if (c >= x + num / 2)
        {
            // 4
            if (r >= y + num / 2)
            {
                ans += ((num / 2) * (num / 2) * 3);
                Partition(x + num / 2, y + num / 2, num / 2);
            }
            // 2
            else
            {
                ans += ((num / 2) * (num / 2));
                Partition(x + num / 2, y, num / 2);
            }
        }
        // 1, 3
        else
        {
            // 3
            if (r >= y + num / 2)
            {
                ans += ((num / 2) * (num / 2) * 2);
                Partition(x, y + num / 2, num / 2);
            }
            // 1
            else
            {
                Partition(x, y, num / 2);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> r >> c;
    int num = (int)pow(2, N);
    Partition(0, 0, num);

    return 0;
}