#include <bits/stdc++.h>

using namespace std;

vector<int> v(1001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> v2;
    v2.emplace_back(v[0]);

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < v2.size(); j++)
        {
            // 앞에서 부터 순회를 하다 더 큰 수를 만났다면. -> 해당 수를 대치한다.
            if (v2[j] >= v[i])
            {
                v2[j] = v[i];
                break;
            }

            if (j == (v2.size() - 1))
                v2.emplace_back(v[i]);
        }
    }

    cout << v2.size();

    return 0;
}