#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sum = 0;

void subset(vector<int> seq, int x, int target, int& answer){

    if (sum == target){
	    answer++;
	}
    
	for (int i = x; i < seq.size(); i++){
		sum += seq[i];
        sum += seq[i];
        
		subset(seq, i+1, target, answer);
        
		sum -= seq[i];  
        sum -= seq[i];  
	}
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    for(int i = 0; i < numbers.size(); i++){
        sum -= numbers[i];
    }
    subset(numbers, 0 , target, answer);
    return answer;
}