#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, B, C;
    cin >> N;

    vector<int> room(N);
    for (int i = 0; i < N; i++)
        cin >> room[i];

    cin >> B >> C;
    long long ans = N;

    for (int i = 0; i < N; i++)
    {
        if (room[i] - B >= 0)
            room[i] -= B;
        else
            continue;
        ans += room[i] % C != 0 ? room[i] / C + 1 : room[i] / C;
    }

    cout << ans;

    return 0;
}
