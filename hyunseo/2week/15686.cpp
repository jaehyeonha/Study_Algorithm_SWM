#include <bits/stdc++.h>

#define INF 2e9

using namespace std;

typedef pair<int, int> pii;
vector<vector<int>> v(51, vector<int>(51, 0));
vector<pii> chicken;
vector<pii> house;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 2)
                chicken.emplace_back(i, j);
            if (v[i][j] == 1)
                house.emplace_back(i, j);
        }

    vector<vector<int>> v2(house.size(), vector<int>(chicken.size(), 0));

    for (int i = 0; i < house.size(); i++)
        for (int j = 0; j < chicken.size(); j++)
            v2[i][j] = abs((house[i].first - chicken[j].first)) + abs(house[i].second - chicken[j].second);

    // cout << "v2 ===============" << endl;
    // for (auto i : v2)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    vector<int> v3;
    for (int i = 0; i < chicken.size(); i++)
        v3.push_back(i);
    vector<bool> v4(v3.size() - M, false);
    v4.insert(v4.end(), M, true);
    int min_chicken_distance = INF;

    do
    {
        int sum = 0;

        // 집의 개수만큼 반복해야 한다.
        for (int j = 0; j < v2.size(); j++)
        {
            int answer = INF;
            for (int i = 0; i < v3.size(); i++)
            {
                if (v4[i])
                {
                    if (answer > v2[j][i])
                        answer = v2[j][i];
                }
            }
            sum += answer;
        }
        if (min_chicken_distance > sum)
            min_chicken_distance = sum;

    } while (next_permutation(v4.begin(), v4.end()));

    cout << min_chicken_distance;

    return 0;
}