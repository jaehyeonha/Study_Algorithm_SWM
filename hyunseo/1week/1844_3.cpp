#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int solution(vector<vector<int>> maps)
{
    int N = maps.size(), M = maps[0].size();

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue<pair<int, int>> queue;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> distance(N, vector<int>(M, 0));

    visited[0][0] = true;

    // 초기에는 자신이니까 간 거리를 1으로 한다.
    distance[0][0] = 1;

    // 0, 0좌표 집어넣기
    queue.push(make_pair(0, 0));

    // queue가 비지 않을떄 동안
    while (!queue.empty())
    {
        // x, y좌표 꺼내오기
        int x = queue.front().first, y = queue.front().second;

        queue.pop();

        // 4방향 탐색
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> nextPos = make_pair(x + dir[i][1], y + dir[i][0]);

            if (nextPos.first >= 0 && nextPos.first < N && nextPos.second >= 0 && nextPos.second < M && maps[nextPos.first][nextPos.second] && !visited[nextPos.first][nextPos.second])
            {
                visited[nextPos.first][nextPos.second] = true;
                distance[nextPos.first][nextPos.second] = distance[x][y] + 1;
                queue.push(nextPos);
            }
        }
    }

    if (!distance[N - 1][M - 1])
        return -1;

    return distance[N - 1][M - 1];
}

int main()
{
    cin >> N >> M;
    vector<vector<int>> maps(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> maps[i][j];

    cout << solution(maps) << endl;

    return 0;
}