#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector <pair<int,int>> LR;

int binsearch(int low, int high, int T){
    int mid;
    while (low < high) {
        int sum = 0;
        int flag = 0;
        mid = (low + high) / 2;
        for (int i = 0; i < LR.size(); i++) {
			if (LR[i].first > mid) {
                flag = 1;
                break;
		    }
            sum += min(mid, LR[i].second);
        }
        if(flag == 1 || sum <T){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return high;
}

int main()
{
    int N, T;
    cin >> N >> T;

    int min = 0, max = 0;
 
    for(int i = 0; i < N ; i++){
        int L, R;
        cin >> L >> R;
        LR.push_back({L,R});
        min += L;
        max += R;
    }
    if(min > T || max < T){
        cout << -1 << endl;
    }
    else   
        cout << binsearch(0,1000000000, T) << endl;

    return 0;
}