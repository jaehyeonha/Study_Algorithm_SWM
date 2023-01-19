#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, S;
vector<int> seq;
int sum = 0;
int count = 0;

void subset(int x){

	for (int i = x; i < N; i++){
		sum += seq[i];
        if (sum == S){
		    count++;
	    }
		subset(i+1);

		sum -= seq[i];
	}
}

int main()
{
    cin >> N >> S;
    seq.resize(N);

    for(int i = 0; i < N; i++){
        cin >> seq[i];
    }

    subset(0);

    cout << count << endl;

    return 0;
}