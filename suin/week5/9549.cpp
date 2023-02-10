#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
int alpha[27];
int check[27];

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(alpha, 0, sizeof(alpha));
        string test, ori;
        cin >> test >> ori;
        for(int i=0; i<ori.size(); i++){
            alpha[ori[i]-'a']++;
        }
        queue<char> q;
        copy(alpha,alpha+27,check);

        for(int i=0; i<test.size(); i++){
            if(q.size() == ori.size()){
                break;
            }
            if(check[test[i]-'a']){
                check[test[i]-'a']--;
                q.push(test[i]);
            }
            else{
                while(!q.empty()){
                    if(q.front()==test[i]){
                        q.pop();
                        q.push(test[i]);
                        break;
                    }
                    check[q.front()-'a']++;
                    q.pop();
                }
                if(!q.empty()){
                    continue;
                }
                copy(alpha,alpha+27,check);
                queue<char> a;
                q = a;
                if(check[test[i]-'a']){
                    check[test[i]-'a']--;
                    q.push(test[i]);
                }
                    
            }
        }

        if(q.size() == ori.size()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}