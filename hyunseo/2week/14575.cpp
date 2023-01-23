#include <bits/stdc++.h>

#define INF 2e9
using namespace std;
typedef pair<int, int> pii;
vector<pii> arr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, T;
    cin >> N >> T;
    int L, R;
    pii sum = {0, 0}, answer = {-INF, -INF};
    for (int i = 0; i < N; i++)
    {
        cin >> L >> R;
        arr.emplace_back(L, R);
        sum.first += L;
        sum.second += R;
        if (answer.first < L)
            answer.first = L;
        if (answer.second < R)
            answer.second = R;
    }

    if (sum.first > T || sum.second < T)
    {
        cout << "-1";
        return 0;
    }

    int right = INF;
    int left = answer.first;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int S = mid;
        int inner_sum = 0;
        for (const auto &p : arr)
        {
            if (S > p.second)
                inner_sum += p.second - p.first;
            else
                inner_sum += S - p.first;
        }
        if (inner_sum >= T - sum.first)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left << endl;
    return 0;
}