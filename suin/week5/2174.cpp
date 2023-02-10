#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

struct robot{
    int x, y, dx, dy;
    char direction;
};

int A, B, N, M;
map<int, pair<int,int> > dir;
map<char,char> L;
map<char,char> R;
int ar[101][101];
vector<robot> robots;

int main(){
    //NWES
    dir.insert(make_pair('N', make_pair(0,1)));
    dir.insert(make_pair('W', make_pair(-1,0)));
    dir.insert(make_pair('E', make_pair(1,0)));
    dir.insert(make_pair('S', make_pair(0,-1)));
    L.insert(make_pair('N','W'));
    L.insert(make_pair('W','S'));
    L.insert(make_pair('S','E'));
    L.insert(make_pair('E','N'));
    R.insert(make_pair('N','E'));
    R.insert(make_pair('E','S'));
    R.insert(make_pair('S','W'));
    R.insert(make_pair('W','N'));

    cin >> A >> B >> N >> M;
    robot robot_zero;
    robots.push_back(robot_zero);
    for(int i=0; i<N; i++){
        robot r;
        string c;
        cin >> r.x >> r.y >> c;
        r.dx = dir[c[0]].first;
        r.dy = dir[c[0]].second;
        r.direction = c[0];
        ar[r.x][r.y] = i+1;
        robots.push_back(r);
    }

    for(int i=0; i<M; i++){
        int num, repaet_num;
        string cmd;
        cin >> num >> cmd >> repaet_num;
        if(cmd == "F"){
            for(int j=0; j<repaet_num; j++){
                ar[robots[num].x][robots[num].y] = 0;
                robots[num].x += robots[num].dx; 
                robots[num].y += robots[num].dy; 
                if(0 < robots[num].x&&robots[num].x<=A&&0 < robots[num].y&&robots[num].y<=B){
                    if(ar[robots[num].x][robots[num].y]==0){
                        ar[robots[num].x][robots[num].y] = num;
                    }else{
                        cout << "Robot "<< num <<" crashes into robot " << ar[robots[num].x][robots[num].y];
                        return 0;
                    }
                }else{
                    cout << "Robot "<< num <<" crashes into the wall";
                    return 0;
                }   
            }
        }else if(cmd == "R"){
            for(int j=0; j<repaet_num; j++){
                robots[num].direction = R[robots[num].direction];
            }    
            robots[num].dx = dir[robots[num].direction].first;
            robots[num].dy = dir[robots[num].direction].second;
        }else{
            for(int j=0; j<repaet_num; j++){
                robots[num].direction = L[robots[num].direction];
            }    
            robots[num].dx = dir[robots[num].direction].first;
            robots[num].dy = dir[robots[num].direction].second;
        }
    }
    cout << "OK";
    return 0;
}