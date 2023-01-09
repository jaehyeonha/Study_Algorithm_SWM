#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;

int find_path(vector<vector<int>> maps, int row, int col, int distance, vector<vector<bool>> visited)
{
    vector<vector<bool>> visited_copy(visited);

    // 만약 path의 row, col이 범위 밖이고
    if (row < 0 || col < 0 || row >= maps.size() || col >= maps[0].size() ||
        // row, col이 지나갈 수 없고, 이미 방문한 곳이라면 -> INT_MAX 반환
        !maps[row][col] || visited_copy[row][col])
        return INT_MAX;

    // row, col이 끝에 도달했다면
    if (row == maps[0].size() - 1 && col == maps.size() - 1)
    {
        distance++;
        return distance;
    }

    // distance는 말 그대로 시작점으로부터 지나온 거리를 의미한다.
    distance++;
    visited_copy[row][col] = true;

    return (min({find_path(maps, row - 1, col, distance, visited_copy),    // 북
                 find_path(maps, row, col + 1, distance, visited_copy),    // 동
                 find_path(maps, row + 1, col, distance, visited_copy),    // 남
                 find_path(maps, row, col - 1, distance, visited_copy)})); // 서
}

int solution(vector<vector<int>> maps)
{
    int n = maps.size(), m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int shortest_dist = find_path(maps, 0, 0, 0, visited);
    if (shortest_dist == (INT_MAX))
        return -1;
    return shortest_dist;
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