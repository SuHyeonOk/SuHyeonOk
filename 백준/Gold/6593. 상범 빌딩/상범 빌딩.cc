// 시간 확인 용










#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <string.h>
using namespace std;
int l, r, c;
char building[31][31][31];
bool visit[31][31][31];
int dx[] = {1,-1,0,0,0,0}; // 동서남북상하
int dy[] = {0,0,-1,1,0,0};
int dz[] = {0,0,0,0,1,-1};
vector<int> result;
bool found = false;
void bfs(int x1, int y1,int z1, int c1){
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(x1, y1, z1, c1));
    visit[z1][y1][x1] = true;
    
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        int cnt = get<3>(q.front());
        if(building[z][y][x]=='E'){
            found = true;  
            result.push_back(cnt);
            break; // 탈출 했을 경우
        }
        q.pop();
        
        for (int i = 0; i < 6;i++){
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            int n_z = z + dz[i];
 
            if (n_x >= 0 && n_y >= 0 && n_z >= 0 && n_x < c && n_y < r && n_z < l){
                if(!visit[n_z][n_y][n_x] && building[n_z][n_y][n_x]!='#'){
                    q.push(make_tuple(n_x, n_y, n_z,cnt+1));
                    visit[n_z][n_y][n_x] = true;
                } 
            }
        }
    }
}
int main(){
    while(1){
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0){
            break; // 000이 들어오면 종료
        }
        int start_x, start_y, start_z;
        memset(visit, false, sizeof(visit));
        found = false;
 
        for (int i = 0; i < l;i++){
            for (int j = 0; j < r; j++){
                for (int k = 0; k < c; k++){
                    cin >> building[i][j][k];
                    if( building[i][j][k] == 'S'){
                        start_x = k;
                        start_y = j;
                        start_z = i; //시작 좌표 저장
                    }
                }
            }
        }
        bfs(start_x, start_y, start_z, 0);
        if(!found){ // 탈출을 못했을 경우 
            result.push_back(-1);
        }
    }
    for (int i = 0; i < result.size();i++){
        if(result[i] == -1){
            cout << "Trapped!" << '\n';
        }
        else{
            cout << "Escaped in " << result[i] << " minute(s)." << '\n';
        }
    }
 
    return 0;
}