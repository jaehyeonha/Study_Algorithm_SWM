#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int size =  numbers.size();
    
    queue<pair<int, int>> q;
    //초기값
    q.push(make_pair(numbers[0], 1));
    q.push(make_pair(-numbers[0], 1));
    
    while(!q.empty()){
        //num은 target인지 확인 및 그 다음 numbers 더해주기 위해
        int num = q.front().first;
        //chk는 size가 맞는지 확인용
        int chk = q.front().second;
        q.pop();
        if(chk == size){
            if(num == target)
                answer++;
        }
        else{
            q.push(make_pair(num+numbers[chk], chk+1));
            q.push(make_pair(num-numbers[chk], chk+1));
        }
    }
    return answer;
}