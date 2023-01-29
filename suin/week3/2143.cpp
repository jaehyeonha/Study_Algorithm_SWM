#include<iostream>
#include<vector>
#include<map>

using namespace std;

int N, A, B;
vector<int> a;
vector<int> b;
int main(){

    cin >> N;
    cin >> A;
    for(int i=0; i<A; i++){
        int t;
        cin >> t;
        a.push_back(t);
        if(i!=0){
            a[i] = a[i]+a[i-1];
        }
    }
    cin >> B;
    for(int i=0; i<B; i++){
        int t;
        cin >> t;
        b.push_back(t);
        if(i!=0){
            b[i] = b[i]+b[i-1];
        }
    }
    
    map<int,int> m1;
    map<int,int> m2;

    int sum;
    for(int i=0;i<A;i++){
        for(int j=0; j<i; j++){
            sum = a[i]-a[j];
            if(m1.find(sum)!=m1.end()){
                m1[sum]++;
            }else{
                m1.insert(make_pair(sum,1));
            }
            //cout << sum << " : " << m1[sum] << endl;
        }
        sum = a[i];
        if(m1.find(sum)!=m1.end()){
            m1[sum]++;
        }else{
            m1.insert(make_pair(sum,1));
        }
        //cout << sum << " : " << m1[sum] << endl;
    }

    for(int i=0;i<B;i++){
        for(int j=0; j<i; j++){
            sum = b[i]-b[j];
            if(m2.find(sum)!=m2.end()){
                m2[sum]++;
            }else{
                m2.insert(make_pair(sum,1));
            }
        }
        sum = b[i];
        if(m2.find(sum)!=m2.end()){
            m2[sum]++;
        }else{
            m2.insert(make_pair(sum,1));
        }
    }
    long result = 0;
    int next;

    map<int,int> :: iterator iter;

    for(iter = m1.begin(); iter != m1.end(); iter++){
        next = N - iter->first;
        if(m2.find(next)!=m2.end()){
            result += iter->second * long(m2[next]);
            //cout << iter->first << " : " << iter->second << " + " << next <<" : " <<  m2[next] <<" = "<< result<< endl;
        }else{
            //cout << iter->first << " : " << iter->second << endl;
        }
    }

    cout << result;

    return 0;
}