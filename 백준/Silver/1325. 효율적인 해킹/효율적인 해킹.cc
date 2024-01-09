#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10001
using namespace std;

int N{ 0 }, M{ 0 }, hacked{ 1 };
vector<int> map[MAX];
vector<pair<int, int>> vec; // <컴퓨터 번호, 해킹 가능한 컴퓨터 수> 벡터
bool visited[MAX];

void DFS(int _x) 
{
    visited[_x] = true;

    for (int w = 0; w < map[_x].size(); w++) 
    {
        int nv = map[_x][w];

        if (visited[nv] == 0) 
        {
            visited[nv] = true;
            DFS(nv);
            hacked++;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int a{ 0 }, b{ 0 };
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        map[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) 
    {
        DFS(i);
        memset(visited, false, sizeof(visited));
        vec.push_back({ i, hacked });
        hacked = 1;
    }

    //해킹 가능한 최대 컴퓨터 수 구하기
    int maxHack{ -1 };
    int size{ static_cast<int>(vec.size()) };
    for (int i = 0; i < size; i++)
    {
        if (vec[i].second > maxHack) 
        {
            maxHack = vec[i].second;
        }
    }

    //maxHack에 해당하는 컴퓨터 번호 모두 출력
    for (int i = 0; i < size; i++)
    {
        if (vec[i].second == maxHack) 
        {
            cout << vec[i].first << " ";
        }
    }

    return 0;
}
