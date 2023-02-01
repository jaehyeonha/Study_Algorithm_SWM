#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<string>

using namespace std;

long long T;
long long K;
priority_queue<long long,vector<long long> ,greater<long long> > qg;
priority_queue<long long> ql;
map<long long,long long> m;
int main(){
    cin >> T;
    for(long long i=0;i<T;i++){
        cin >> K;

        for(long long j=0;j<K;j++){
            string cmd;
            cin >> cmd;
            long long t;
            cin >> t;
            if(cmd == "I"){
                if(m.find(t)==m.end()){
                    m.insert(make_pair(t,1));
                }else{
                    m[t]++;
                }
                qg.push(t);
                ql.push(t);
            }else{
                if(t!=1){
                    while(m.find(qg.top())==m.end()){
                        if(m.size()==0){
                            break;
                        }
                        if(qg.size()!=0){
                            qg.pop();
                        }
                    }
                    if(m.find(qg.top())!=m.end()){
                        if(m[qg.top()]==1){
                            m.erase(qg.top());
                        }else{
                            m[qg.top()]--;
                        }
                    }
                    if(qg.size()!=0){
                        qg.pop();
                    }
                }else{
                    while(m.find(ql.top())==m.end()){
                        if(m.size()==0){
                            break;
                        }
                        if(ql.size()!=0){
                            ql.pop();
                        }
                    }
                    if(m.find(ql.top())!=m.end()){
                        if(m[ql.top()]==1){
                            m.erase(ql.top());
                        }else{
                            m[ql.top()]--;
                        }
                    }
                    if(ql.size()!=0){
                        ql.pop();
                    }
                }
            }
        }
        if(m.size()==0){
            cout <<  "EMPTY" << endl;
        }else{
            while(m.find(qg.top())==m.end()){
                qg.pop();
            }
            while(m.find(ql.top())==m.end()){
                ql.pop();
            }
            cout <<   ql.top()<<" "<<qg.top()<<endl;
        }

    }
}