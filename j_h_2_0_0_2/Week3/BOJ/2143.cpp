#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<int,int> sumA;

int main()
{   
    int T;
    cin >> T;
    
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int M;
    cin >> M;
    vector<int> B(M);
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }

    long long answer = 0;
    long long sum = 0;

    for(int i = 0; i < N; i++){
        sum = 0;
        for(int j = i; j < N; j++){
            sum += A[j];
            if(sumA.find(sum) != sumA.end()){
                sumA[sum]++;
            }
            else{
                sumA.insert(make_pair(sum,1));
            }
        }
    }

    for(int i = 0; i < M; i++){
       sum = 0;
        for(int j = i; j < M; j++){
            sum += B[j];
            if(sumA.find(T-sum) !=  sumA.end()){
                answer += sumA[T-sum]; 
            }
        }
    }
    cout << answer << endl;;
}