#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<vi> vvi;

template <typename T>
void cpout(T v) { cout << v << '\n'; }

bool comp(const pii &a, const pii &b)
{
    return a.first < b.first;
}

vi A, B;

int T, n, m;

int main()
{
    fastio;
    cin >> T;
    cin >> n;
    int v;

    for (int i = 0; i < n; i++)
    {
        cin >> v;
        A.emplace_back(v);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v;
        B.emplace_back(v);
    }

    vpii vp1;
    vpii::iterator it;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            if ((it = find_if(vp1.begin(), vp1.end(), [&vp1, sum](const pii &a)
                              { return a.first == sum; })) != vp1.end())
                it->second++;
            else
                vp1.emplace_back(sum, 1);
        }
    }

    vpii vp2;
    for (int i = 0; i < m; i++)
    {
        sum = 0;
        for (int j = i; j < m; j++)
        {
            sum += B[j];
            if ((it = find_if(vp2.begin(), vp2.end(), [&vp2, sum](const pii &a)
                              { return a.first == sum; })) != vp2.end())
                it->second++;
            else
                vp2.emplace_back(sum, 1);
        }
    }
    sort(vp1.begin(), vp1.end(), comp);
    sort(vp2.begin(), vp2.end(), comp);

    // for (auto v : vp1)
    // {
    //     cout << "( " << v.first << " " << v.second << " ) ";
    // }
    // cout << '\n';

    // for (auto v : vp2)
    // {
    //     cout << "( " << v.first << " " << v.second << " ) ";
    // }
    // cout << '\n';

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += vp1[i].second * lower_bound(vp2.begin(), vp2.end(), pii(T - vp1[i].second, 0), comp)->second;

    cout << ans;
    return 0;
}