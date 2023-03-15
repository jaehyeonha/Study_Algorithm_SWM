#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, L, R, X;
vector<int> A;
int answer = 0;

int sum = 0;
int cnt = 0;

void subset(int x, int mi, int ma){
    
    if(cnt>=2 && L <= sum && R >= sum && (ma-mi) >= X){
        answer++;
    }

	for (int i = x; i < N; i++){
		sum += A[i];
        cnt++;
		subset(i+1, min(A[i],mi) ,max(A[i],ma));

		sum -= A[i];
        cnt--;
	}
}

int main()
{
    cin >> N >> L >> R >> X;
    A.resize(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    subset(0, 999999999, 0);

    cout << answer << endl;

}
