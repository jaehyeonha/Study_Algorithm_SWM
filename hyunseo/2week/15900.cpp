#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int C, N, M, tree_depth_count;

vector<vector<int>> matrix(500001, vector<int>());
vector<bool> visited(500001, false);

int dfs(int index, int depth)
{
    int local_count = 0;

    if (index != 1 && (matrix[index].size() == 1))
    {
        return depth;
    }

    visited[index] = true;
    for (const auto &target : matrix[index])
    {
        // 만약 방문하지 않았다면
        if (!visited[target])
        {
            // i번째로 dfs를 돌려주고, 깊이는 1을 추가해 주어야 한다.
            local_count += dfs(target, depth + 1);
        }
    }

    return local_count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> C;
    for (int i = 0; i < C - 1; i++)
    {
        cin >> N >> M;
        // 인접 리스트로 구현해야 함.
        matrix[N].push_back(M), matrix[M].push_back(N);
    }

    if (dfs(1, 0) % 2 == 0)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}