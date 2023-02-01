#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<string>

using namespace std;

priority_queue<int, vector<int>, greater<int> > minheap;
priority_queue<int> maxheap;
map<int, int> m;
int T, K;
string cmd;
int input;

void insert_number(){
    if(m.find(input)==m.end()) {
        // input이 한번도 주어지지 않았다면
        m.insert(make_pair(input,1));
    }else{
        m[input]++;
    }
    maxheap.push(input);
    minheap.push(input);
}
void delete_number(int target){
    m[target]--;
    if(m[target] <= 0){
        m.erase(target);
    }
}
void delete_max_number(){
    // 2. 현재 큐가 비어있다면
    if(m.size()==0){
        return;
    }

    // 3. input이 큐에 존재하고 빼내야 한다.
    int cur_maxa = maxheap.top();
    while( m.find(cur_maxa) == m.end() ) {
        // 만약 현재 살펴본 맥스가 큐에 없어야 하는 수라면 다음 수를 본다.
        maxheap.pop();
        cur_maxa = maxheap.top();
    }
    delete_number(cur_maxa);
    
}
void delete_min_number(){
    // 2. 현재 큐가 비어있다면
    if(m.size()==0){
        return;
    }

    // 3. input이 큐에 존재하고 빼내야 한다.
    int cur_mina = minheap.top();
    while( m.find(cur_mina) == m.end() ) {
        // 만약 현재 살펴본 맥스가 큐에 없어야 하는 수라면 다음 수를 본다.
        minheap.pop();
        cur_mina = minheap.top();
    }
    delete_number(cur_mina);
}

void print_result(){
    if(m.size()==0){
        cout << "EMPTY" << endl;
    }else{
        int cur_maxa = maxheap.top();
        while( m.find(cur_maxa) == m.end() ) {
            // 만약 현재 살펴본 맥스가 큐에 없어야 하는 수라면 다음 수를 본다.
            maxheap.pop();
            cur_maxa = maxheap.top();
        }
        int cur_mina = minheap.top();
        while( m.find(cur_mina) == m.end() ) {
            // 만약 현재 살펴본 맥스가 큐에 없어야 하는 수라면 다음 수를 본다.
            minheap.pop();
            cur_mina = minheap.top();
        }
        cout << cur_maxa << " " << cur_mina << endl;
    }
}
int main(){
    cin >> T;
    while(T--){
        cin >> K;
        while(K--){
            cin >> cmd;
            cin >> input;
            if(cmd == "I"){
                insert_number();
            }else if(input == 1){
                delete_max_number();
            }else{
                delete_min_number();
            }
            //print_result();
        }
        print_result();

        map<int, int> m1;
        m= m1;
    }
    
    return 0;
}
// 테스트 케이스는 초기화 했는지 확인하기!