#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef queue<pii> qpii;

template <typename T>
void cpout(T v) { cout << v << '\n'; }

int R, C;
int min_time = 0;

vpii dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vvc td_map(53, vc(51, 0));
vvb visited(53, vb(51, false));
qpii water_q;

pii hedgehog_pos;

bool check;

void printMap()
{
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
            cout << td_map[i][j] << " ";
        cout << '\n';
    }
}

// 말 그대로 경기장 안에 있는지 판단.
bool isInMap(int i, int j)
{
    return (i >= 1 && i <= R && j >= 1 && j <= C);
}

// 사방에 물이 하나라도 있는지 확인해야 한다. + (반례) 현재 위치도 물이여서는 안된다.
bool currentAndnextPosHasNoWater(int x, int y)
{
    // 만약 현재 위치가 물이라면 false를 리턴
    if (td_map[x][y] == '*')
        return false;

    // 그리고 사방에 물이 하나라도 있다면 false를 리턴한다.
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i].first, ny = y + dir[i].second;
        if (!isInMap(nx, ny))
            continue;

        // 사방에 돌이 있다면 가지 못한다.
        if (td_map[nx][ny] == '*')
            return false;
    }

    // 그게 아니라면 가능한 경우다.
    return true;
}

// 지도를 벗어나지 않았고, 돌멩이가 아니여야 하며, 사방에 물이 없어야 하고, 방문하지 않은 곳이여야 한다. ( 우선순위가 가장 낮아서 맨 뒤에! )
bool canGo(int i, int j)
{
    // 모든 내용을 종합해서 다음 위치로 갈 수 있는지 판단한다.
    return (isInMap(i, j) && td_map[i][j] != 'X' && currentAndnextPosHasNoWater(i, j) && !visited[i][j]);
}

bool bfs()
{
    qpii q;
    q.emplace(hedgehog_pos);
    visited[hedgehog_pos.first][hedgehog_pos.second] = true;

    while (!q.empty())
    {
        int hedgehog_queue_size = q.size();

        check = false;
        while (hedgehog_queue_size--)
        {
            pii cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dir[i].first, ny = cur.second + dir[i].second;

                // 만약 다음 위치가 'D'즉 비버 동굴이라면, min_time을 하나 증가시키고 바로 return하면 된다.
                if (td_map[nx][ny] == 'D')
                {
                    min_time++;
                    return true;
                }

                // 가능 여부 판단.
                if (!canGo(nx, ny))
                    continue;

                // 큐에 다음 위치 삽입.
                q.emplace(nx, ny);
                // 다음위치 방문기록.
                visited[nx][ny] = true;

                // 그리고 이동한 칸을 표시해 주어야 한다.
                td_map[nx][ny] = 'S';
                check = true;
            }
        }

        if (check)
        {
            int q_size = water_q.size();
            // 실제로 움직였다면, 비어있는 칸을 물로 채워야 한다.
            for (int i = 0; i < q_size; i++)
            {
                int wx = water_q.front().first, wy = water_q.front().second;

                water_q.pop();

                for (int j = 0; j < 4; j++)
                {
                    int wnx = wx + dir[j].first, wny = wy + dir[j].second;
                    // (wnx, wny)이 지도 안 이여야 하고, 바꾸려는게 무조건 '.'이여야 한다.
                    if (!isInMap(wnx, wny) || td_map[wnx][wny] != '.')
                        continue;

                    td_map[wnx][wny] = '*';
                    water_q.emplace(wnx, wny);
                }
            }
            // 아무것도 변경하지 않았으면, 그냥 큐에서 빼내는 작업만 했으면 min_time을 증가시켜서는 안된다.
            min_time++;
            // cout << "-------------------------" << '\n';
            // printMap();
        }
    }

    // 만약 비버 동굴을 찾지 못했다면, KAKTUS를 출력해야 한다.
    return false;
}

int main()
{
    fastio;

    cin >> R >> C;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            cin >> td_map[i][j];
            if (td_map[i][j] == '*')
                water_q.emplace(i, j);
            if (td_map[i][j] == 'S')
                hedgehog_pos = make_pair(i, j);
        }

    visited[hedgehog_pos.first][hedgehog_pos.second] = true;

    bfs() ? cout << min_time : cout << "KAKTUS";

    return 0;
}