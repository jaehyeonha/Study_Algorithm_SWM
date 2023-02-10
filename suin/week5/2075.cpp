#include<iostream>
#include<queue>
#include<map>

#define fastio                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
#define endl '\n'

using namespace std;

int N, row, mina, col;
int ar[1501][1501];
int cnt[1501];
map<int,int> m;

int main(){
    fastio;
    cin >> N;
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            cin >> ar[r][c];
            cnt[c]++;
        }
    }

    for(int c=0; c<N; c++){
        m.insert(make_pair(ar[N-1][c],c));
        cnt[c]--;
    }
    
    for(int c=0; c<N-1; c++){
        mina = (m.rbegin())->first;
        col = m[mina];
        m.erase(mina);
        row = --cnt[col];
        m.insert(make_pair(ar[row][col],col));
    }

    cout << (m.rbegin())->first;
    return 0;
}