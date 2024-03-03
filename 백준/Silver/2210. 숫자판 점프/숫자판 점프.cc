#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[5][5];
int dy[4] { 0,0,-1,1 };
int dx[4] { -1,1,0,0 };
vector<int> vec;

void DFS(int Y, int X, int Number, int Count) 
{
    if (Count == 6) 
    {
        vec.push_back(Number);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = Y + dy[i];
        int nx = X + dx[i];

        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
        {
            continue;
        }

        DFS(ny, nx, Number * 10 + map[ny][nx], Count + 1);
    }
}

int main() 
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            DFS(i, j, 0, 0);
        }
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    cout << vec.size();

    return 0;
}