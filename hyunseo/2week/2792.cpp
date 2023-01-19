#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

vector<int> v(300001, 0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int sum = 0, max = -INF;
    for (int i = 0; i < M; i++)
    {
        cin >> v[i];
        sum += v[i];
        if (max < v[i])
            max = v[i];
    }

    int right = max;
    int left = 1, result = INF;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        int cnt2 = 0;
        for (int i = 0; i < M; i++)
        {
            if (v[i] > mid)
            {
                cnt2 += v[i] / mid;
                if (v[i] % mid)
                    cnt2++;
            }
            else
                cnt2++;
        }

        if (cnt2 <= N)
        {
            if (result > mid)
                result = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << result;
    return 0;
}