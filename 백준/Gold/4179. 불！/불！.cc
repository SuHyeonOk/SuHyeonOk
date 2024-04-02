#include <iostream>
#include <queue>
using namespace std;

struct xy { int x, y; };

int R, C;
char maze[1000][1001]; // 널문자 고려
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<xy> J, F;

void firesSpread() {
    int size = F.size();
    while(size--) {
        int x = F.front().x, y = F.front().y; F.pop();
        for(int i=4; i--;) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(maze[nx][ny]=='#') continue;
            maze[nx][ny] = '#';
            F.push({nx, ny});
        }
    }
}

bool JihoonEscapes() {
    int size = J.size();
    if(size == 0) {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    while(size--) {
        int x = J.front().x, y = J.front().y; J.pop();
        if(x == 0 || x == R-1 || y == 0 || y == C-1) return true;
        for(int i=4; i--;) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(maze[nx][ny]=='#') continue;
            maze[nx][ny] = '#';
            J.push({nx, ny});
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    for(int i=0; i<R; i++) {
        cin >> maze[i];
        for(int j=0; j<C; j++) {
            if(maze[i][j] == 'J') {
                J.push({i, j});
                maze[i][j] = '#';
            }
            else if(maze[i][j] == 'F') {
                F.push({i, j});
                maze[i][j] = '#';
            }
        }
    }

    int step = 0;
    do {
        firesSpread();
        step++;
    } while(!JihoonEscapes());
    cout << step;
}