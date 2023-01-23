#include<iostream>
#include<vector>

using namespace std;

int row, col;
char map[251][251];

int sheep = 0, wolf = 0;
int sheep_total = 0, wolf_total = 0;

void DFS(int x, int y){
  if(x < 0 || x >= row || y < 0 || y >= col){
    return;
  }
  if(map[x][y] == '#'){
    return;
  }
  if(map[x][y] == 'v'){
    wolf++;
  }
  else if(map[x][y] == 'o'){
    sheep++;
  }
  map[x][y] = '#';
  DFS(x-1, y);
  DFS(x+1, y);
  DFS(x, y-1);
  DFS(x, y+1);
}


int main(){
  cin >> row >> col;
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cin >> map[i][j];
    }
  }

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(map[i][j] != '#'){
        DFS(i, j);
        if(sheep > wolf){
          sheep_total += sheep;
        }
        else{
          wolf_total += wolf;
        }
      }
      sheep = 0;
      wolf = 0;
    }
  }
  cout << sheep_total << " " << wolf_total;

  return 0;
}