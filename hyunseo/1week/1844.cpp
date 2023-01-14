#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;

int find_path(vector<vector<int>> maps, int row, int col, int distance, vector<vector<int>> visited)
{
    vector<vector<int>> visited_copy(visited);
    // 만약 벽이 막혔으면 그리고 이미 방문한 곳이면.
    if (!maps[row][col] || visited[row][col])
        return INT_MAX;

    // maps[5][5]는 다 도착한것임.
    if (row == maps[1].size() - 2 && col == maps.size() - 2)
    {
        distance++;
        // cout << "return distance: " << distance << endl;
        return distance;
    }

    // distance는 말 그대로 시작점으로부터 지나온 거리를 의미한다.
    distance++;
    // cout << "row: " << row << " col: " << col << " distance: " << distance << endl;
    visited_copy[row][col] = 1;

    // min을 찾는데, 0을 제외한 것으로 찾고 싶음.
    return (min({find_path(maps, row - 1, col, distance, visited_copy), // 북

                 find_path(maps, row, col + 1, distance, visited_copy), // 동

                 find_path(maps, row + 1, col, distance, visited_copy), // 남
                 // find_path(2, 1) -> 안방문한 곳, 뚫린 곳, 끝x distance = 2

                 // find_path(1, 1) -> 방문한 곳
                 // find_path(2, 2) -> 막힌 곳

                 // find_path(3, 1) -> 갈 수 있음 distance = 3

                 find_path(maps, row, col - 1, distance, visited_copy)})); // 서
}

int solution(vector<vector<int>> maps)
{
    vector<vector<int>> visited(N + 2, vector<int>(M + 2, 0));
    return find_path(maps, 1, 1, 0, visited);
}

int main()
{
    cin >> N >> M;
    vector<vector<int>> maps(N + 2, vector<int>(M + 2, 0));

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> maps[i][j];

    cout << solution(maps) << endl;

    return 0;
}