#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

char arr[12][6];
bool visited[12][6];
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

// DFS를 사용한 Flood Fill
int DFS(int X, int Y, char Color, vector<pair<int, int>>& pos)
{
    int Count = 1;
    visited[Y][X] = true;
    pos.push_back({ Y, X });

    for (int i = 0; i < 4; ++i)
    {
        int Nx = X + dx[i];
        int Ny = Y + dy[i];

        if (Nx >= 0 && Nx < 6 && Ny >= 0 && Ny < 12 && !visited[Ny][Nx] && arr[Ny][Nx] == Color)
        {
            Count += DFS(Nx, Ny, Color, pos);
        }
    }

    return Count;
}

// 블록을 아래로 떨어뜨리는 함수
void MoveBlocks()
{
    for (int X = 0; X < 6; ++X)
    {
        int EmptyRow = 11; // 아래쪽에서부터 채워 나감
        for (int Y = 11; Y >= 0; --Y)
        {
            if (arr[Y][X] != '.')
            {
                arr[EmptyRow--][X] = arr[Y][X];
            }
        }

        while (EmptyRow >= 0) // 나머지 위쪽은 빈 공간으로
        {
            arr[EmptyRow--][X] = '.';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력 처리
    for (int Y = 0; Y < 12; ++Y)
    {
        for (int X = 0; X < 6; ++X)
        {
            cin >> arr[Y][X];
        }
    }

    int ChainCount = 0;
    while (true)
    {
        bool Exploded = false;
        memset(visited, false, sizeof(visited));

        for (int Y = 0; Y < 12; ++Y)
        {
            for (int X = 0; X < 6; ++X)
            {
                if (arr[Y][X] != '.' && false == visited[Y][X])
                {
                    vector<pair<int, int>> pos;
                    if (4 <= DFS(X, Y, arr[Y][X], pos))
                    {
                        Exploded = true;
                        for (pair<int, int>& P : pos)
                        {
                            arr[P.first][P.second] = '.';
                        }
                    }
                }
            }
        }

        if (true == Exploded)
        {
            MoveBlocks();
            ++ChainCount;
        }
        else
        {
            break;
        }
    }

    cout << ChainCount;

    return 0;
}