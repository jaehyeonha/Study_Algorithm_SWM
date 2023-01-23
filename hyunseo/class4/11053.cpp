#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> arr(1000);
vector<int> res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (res.empty() || res.back() < arr[i])
            res.emplace_back(arr[i]);
        else
            *lower_bound(res.begin(), res.end(), arr[i]) = arr[i];
    }

    cout << res.size();

    return 0;
}