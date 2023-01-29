#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int f(vector<int> numbers, int target, int number,int start, int end, int cur){
    // 타겟 넘버를 만들 수 있는 방법의 수 반환
    if(cur > end){
        if(number == target){
            return 1;
        }
        else{
            return 0;
        }
    }
    return f(numbers, target,number+numbers[cur],start,end,cur+1) + f(numbers, target,number-numbers[cur],start,end,cur+1);
}


int f2(vector<int> numbers, int number,int start, int end, int cur, map<int, int>&targets){
    // 만들어질 수 있는 타겟 넘버를 반환 
    if(cur > end){
        if(targets.find(number)!=targets.end()){
            targets[number]++;
        }else{
            targets.insert({number,1});
        }
        return 0;
        
    }
    return f2(numbers, number+numbers[cur],start,end,cur+1,targets) + f2(numbers, number-numbers[cur],start,end,cur+1,targets);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    map<int, int> targets;
    
    cout << numbers.size()/2<< ":";
    // key(중복x) : 만들어질 수 있는 수 
    f2(numbers, 0, 0, numbers.size()/2, 0, targets);
    cout << targets.size() << "\n";
    for(auto iter: targets){
        cout << iter.first << " ";
        answer += iter.second*f(numbers, target, iter.first, numbers.size()/2+1, numbers.size()-1,numbers.size()/2+1);
    }
    
    cout << "\n";
    return answer;
}