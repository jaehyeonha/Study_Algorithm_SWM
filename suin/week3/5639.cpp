#include<iostream>

using namespace std;

int parent[10011];
int child[10011][2];
int root;

void travel(int cur){
    if(child[cur][0]!=0){
        travel(child[cur][0]);
    }
    if(child[cur][1]!=0){
        travel(child[cur][1]);
    }
    cout << cur <<endl;
}
int main(){
    
    int cur;
    int father = -1;
    int grandfa;
    while(true){
        cin >> cur;
        if(cin.eof())break;

        // root 인 경우
        if(father == -1){
            parent[cur] = father;
            root = cur;
            father = cur;
            continue;
        }

        // left child 일 경우
        if( cur < father ){
            child[father][0] = cur;
            parent[cur] = father;
            father = cur;
            continue;
        }
        else{
            //right child 일 경우
            while(father != -1 ){
                if(father!=root){
                    // grandparent 보다 큰지 확인
                    grandfa=parent[father];
                    if(father > grandfa){
                        child[father][1] = cur;
                        parent[cur] = father;
                        father = cur;
                        break;
                    }
                    if(cur < grandfa){
                        // grandfa 보다 작다
                        child[father][1] = cur;
                        parent[cur] = father;
                        father = cur;
                        break;
                    }
                    // grandfa 보다 크다.
                    father = grandfa;
                    
                }else{
                    child[father][1] = cur;
                    parent[cur] = father;
                    father = cur;
                    break;
                }
            }
        }

    }

    travel(root);
    return 0;
    
}