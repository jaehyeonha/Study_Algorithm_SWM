#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector <int> map(101, 0);
    vector <int> visited(101, 0);
    queue<int> q;
    
    for (int i = 0; i < N + M; i++){
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }

    q.push(1);

    while (!q.empty())
    {
        int x = q.front();

        for (int i = 1; i <= 6; i++)
        {
            int y = x + i;
            if(y > 100)
                continue;

            if(map[y] != 0)
                y = map[y];

            if(visited[y] == 0)
            {   
                visited[y] = visited[x] + 1;
                q.push(y);
            }
        }
            
        q.pop();
    }

    cout << visited[100] << endl;
    
}