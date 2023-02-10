#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int alpha[53][26];
int s;
vector<int> list[53];
queue<int> q;
int visit[53];

void print1(int a){
    cout << a << ": ";
    for(int i=0; i<26; i++){
        cout << alpha[a][i] << " ";
    }
    cout << endl;
}

bool check(int a, int b){
    int res = s;
    for(int i=0; i<26; i++){
        if(alpha[b][i]>0 && alpha[a][i]>0){
            res -= min(alpha[a][i],alpha[b][i]) ;
        }
    }
    print1(a);
    print1(b);
    cout <<"("<<a<<", "<<b << ") res :" << res << endl;
    return (res==1);
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    s = begin.size();
    
    // target과 동일한 words 찾기
    int n = -1;
    for(int i=0; i<words.size(); i++){
        if(target == words[i]){
            n = i+2;
        }
    }
    if(n == -1){
        return 0;
    }
    
    //begin 전처리 : 1
    for(int i=0; i<begin.size(); i++){
        alpha[1][begin[i]-'a']++;
    }
    
    //words 전처리 : 2 ~ N+1
    for(int w=0; w<words.size(); w++){
        for(int i=0; i<begin.size(); i++){
            alpha[w+2][words[w][i]-'a']++;
        } 
    }
    
    //인접 리스트 생성
    for(int i=1; i<(words.size()+2); i++){
        for(int j=1; j<i; j++){
            if(check(i,j)){
                list[i].push_back(j);
                list[j].push_back(i);
            }
        }
    }
    
    // bfs
    int start = 1;
    visit[start] = 1;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<list[cur].size(); i++){
            int next = list[cur][i];
            if(visit[next] == 0){
                visit[next] = visit[cur]+1;
                q.push(next);
            }
        }
    }
    
    // 연결 리스트 확인
    for(int i=1; i<words.size()+2; i++){
        cout << i << ": ";
        for(int j=0; j<list[i].size(); j++){
            cout << list[i][j] << " ";
        }
        cout << endl;
    }
    
    // bfs 결과 프린트
    for(int i=1; i<words.size()+2; i++){
        visit[i]--;
        cout << visit[i] << " ";
    }
    
    
    return visit[n];
}