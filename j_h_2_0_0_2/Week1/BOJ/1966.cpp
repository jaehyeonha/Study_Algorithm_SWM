#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++){
        int N, M;
        cin >> N >> M;
        
        int count = 0;
        int pri;
        queue<pair<int, int>> q;
        vector<int> s;

        for(int j = 0; j < N; j++){
            cin >> pri;
            s.push_back(pri);
            q.push({j, pri});
        }

        sort(s.begin(), s.end(), greater<int>());

        while(!q.empty()){
            if(q.front().second < s[count]){
                q.push(q.front());
            }
            else{
                count++;
                if(q.front().first == M)
                    cout << count << endl;
            }
            q.pop();
        }
    }

    return 0;
}