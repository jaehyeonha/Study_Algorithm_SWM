#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> dx;
 
int main() {
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    int answer = -1;

    vector<int> visited(F + 1, 0);
    queue<int> q;
    dx.push_back(U);
    dx.push_back(D*-1);

    visited[S] = 1;
    q.push(S);
 
    while (!q.empty()) {
        int floor = q.front();

        if(floor == G){
            answer += visited[floor];
            break;
        }
        
        for(int i = 0; i < 2; i++){
            int nextf = floor + dx[i];
            if (0 < nextf && nextf <= F) {
                if (visited[nextf]==0) {
                    visited[nextf] = visited[floor] + 1;
                    q.push(nextf);
                }
            }
        }
        q.pop(); 
    }
 
    if(answer != -1){
        cout << answer << endl;
    }
    else{
        cout << "use the stairs" << endl;
    }
}