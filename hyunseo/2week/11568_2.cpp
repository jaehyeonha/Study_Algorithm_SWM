#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (v.empty() || v.back() < x)
            v.push_back(x);
        else
            *lower_bound(v.begin(), v.end(), x) = x;
    }
    printf("%d", v.size());
    return 0;
}