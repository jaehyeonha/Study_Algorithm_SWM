#include <bits/stdc++.h>

using namespace std;

#define max_size 21
#define INF 401
typedef pair<int, int> pii;

int N, shark_size = 2, min_dis, eat = 0, res = 0;
pii min_pos;

// 상어의 좌표 -> 계속 갱신되어야 하는 값
pii shark;

// 지도 좌표
vector<vector<int>> shark_map(max_size, vector<int>(max_size, 0));

// 아기 상어로부터 거리를 계산하기 위한 vector + 방문했는지 체크용
vector<vector<int>> dis(max_size, vector<int>(max_size, -1));

// 좌표
vector<pii> dir = {
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(0, 1),
    make_pair(-1, 0),
};

// bfs를 이용해서 현재 상어의 위치에서 모든 물고기 까지의 이동거리를 찾고
// 그 중에서 가장 거리가 짧은 물고기를 찾아야 한다. -> 여기서 거리가 같으면 ( 맨 위(1), 맨 왼쪽(2) )
// 우선순위를 적용해서 먹어가야 한다.
void bfs(int dir_x, int dir_y)
{
    queue<pii> q;

    q.emplace(dir_x, dir_y);
    // -1이 아닐떄 조건을 통과하기 위해 초기 아기 상어 위치를 0으로 설정 -> 그리고 가중치 0으로 부터 거리를 계산해야 하기 때문
    dis[dir_x][dir_y] = 0;

    while (!q.empty())
    {
        pii cur = q.front();
        int cur_x = cur.first, cur_y = cur.second;

        q.pop();

        // dir_c는 바뀌는 값이 아님 -> 그냥 위치를 참조하기 위함
        for (const auto &dir_c : dir)
        {
            pii next = {cur_x + dir_c.first, cur_y + dir_c.second};

            int nx = next.first, ny = next.second;

            // 지도 밖으로 나가는 경우는 건너 뛰어야 한다.
            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;

            // 방문한 곳이 아니여야 한다. 그리고 해당 좌표의 크기가 아기 상어보다 크면 안된다. -> 같은 경우는 가도 된다.
            if (dis[nx][ny] != -1 || shark_map[nx][ny] > shark_size)
                continue;

            // 전 좌표에서 가중치를 1 증가시켜야 한다.
            dis[nx][ny] = dis[cur_x][cur_y] + 1;

            // (nx, ny)이 빈칸이 아니고, 아기 상어의 크기보다 작은 경우
            if (shark_map[nx][ny] != 0 && shark_map[nx][ny] < shark_size)
            {
                // CASE1: 더 작은 좌표를 만난 경우 -> 그냥 저장한다
                if (min_dis > dis[nx][ny])
                {
                    min_dis = dis[nx][ny];
                    min_pos = {nx, ny};
                }
                else if (min_dis == dis[nx][ny])
                {
                    // CASE2: 만약 같은 좌표를 만났다면, 더 위에 있는 좌표를 저장한다.
                    // CASE2-1: 만약 y좌표가 다르다면
                    if (min_pos.first > nx)
                    {
                        // ny의 y좌표가 더 작으므로 min_pos에 nx, ny를 넣는다.
                        min_pos = {nx, ny};
                    }
                    else if (min_pos.first == nx)
                    {
                        // CASE2-2: 만약 y좌표가 같다면
                        // 더 왼쪽에 있는 걸 취해야 한다.
                        if (min_pos.second > ny)
                            min_pos = {nx, ny};
                    }
                    // 만약 min_pos.seocnd < ny -> 변경점 없으니까 처리 x
                }
                // cout << "nx : " << nx << " ny : " << ny << " dis : " << dis[nx][ny] << endl;
                // cout << "min_dis : " << min_dis << ", "
                //      << "min_pos : " << min_pos.first << ", " << min_pos.second << endl;
            }
            q.emplace(nx, ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // 지도 입력
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> shark_map[i][j];
            if (shark_map[i][j] == 9)
                // 아기 상어의 초기 위치를 저장
                shark = {i, j};
        }

    // 상어의 초기 위치를 0으로 지정해 주어야 한다.
    shark_map[shark.first][shark.second] = 0;

    while (1)
    {
        // 초기화 하는 과정
        min_dis = INF;
        min_pos = {max_size, max_size};
        fill(dis.begin(), dis.end(), vector<int>(max_size, -1));

        // cout << "( " << shark.first << ", " << shark.second << " )" << endl;
        // bfs -> 완전 탐색
        bfs(shark.first, shark.second);

        // min_x, min_y가 만약 아무것도 바뀌지 않고 초깃값이라면 -> 먹을 수 있는 물고기가 없다는 뜻이다.
        int min_x = min_pos.first, min_y = min_pos.second;

        // min_pos가 갱신되지 않았다면
        if (min_x != max_size && min_y != max_size)
        {
            // 해당 장소로 움직이고 시간을 더해줘야 한다.
            res += dis[min_pos.first][min_pos.second];

            if (++eat == shark_size)
            {
                // 물고기를 먹어서 상어 크기와 가아졌으면, 상어 크기를 1 증가시키고, eat을 0으로 만들어 주어야 한다.
                shark_size++;
                eat = 0;
            }

            // 먹은 물고기 위치를 0으로 만들어 준다.
            shark_map[min_x][min_y] = 0;
            shark = {min_x, min_y};
        }
        else
            break; // 종료조건 -> 아무곳도 이동할 수 없는 경우
    }

    cout << res;

    return 0;
}