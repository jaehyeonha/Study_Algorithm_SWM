#include <bits/stdc++.h>

using namespace std;
int T;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    long long a, b, v, l, ans;
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        v = sqrt((l = b - a));
        pow(v, 2) == l ? (ans = 2 * v - 1) : ans = 2 * v;
        if (l > v * (v + 1))
            ans++;
        cout << ans << '\n';
    }

    return 0;
}