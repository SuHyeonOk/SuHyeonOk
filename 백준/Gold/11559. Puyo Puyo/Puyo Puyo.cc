#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

char Arr[12][6];
bool Visited[12][6];
int Dx[4]{ 0, 0, -1, 1 };
int Dy[4]{ -1, 1, 0, 0 };

// DFS를 사용한 Flood Fill
int Dfs(int X, int Y, char Color, vector<pair<int, int>>& ToPop)
{
    int Count = 1;
    Visited[Y][X] = true;
    ToPop.push_back({ Y, X });
    
    for (int i = 0; i < 4; ++i)
    {
        int Nx = X + Dx[i];
        int Ny = Y + Dy[i];
        
        if (Nx >= 0 && Nx < 6 && Ny >= 0 && Ny < 12 && !Visited[Ny][Nx] && Arr[Ny][Nx] == Color)
        {
            Count += Dfs(Nx, Ny, Color, ToPop);
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
            if (Arr[Y][X] != '.')
            {
                Arr[EmptyRow--][X] = Arr[Y][X];
            }
        }
        while (EmptyRow >= 0) // 나머지 위쪽은 빈 공간으로
        {
            Arr[EmptyRow--][X] = '.';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 처리
    for (int Y = 0; Y < 12; ++Y)
    {
        for (int X = 0; X < 6; ++X)
        {
            cin >> Arr[Y][X];
        }
    }

    int ChainCount = 0;

    while (true)
    {
        bool Exploded = false;
        memset(Visited, false, sizeof(Visited));

        for (int Y = 0; Y < 12; ++Y)
        {
            for (int X = 0; X < 6; ++X)
            {
                if (Arr[Y][X] != '.' && !Visited[Y][X])
                {
                    vector<pair<int, int>> ToPop;
                    int ConnectedBlocks = Dfs(X, Y, Arr[Y][X], ToPop);
                    
                    if (ConnectedBlocks >= 4)
                    {
                        Exploded = true;
                        for (auto [Py, Px] : ToPop)
                        {
                            Arr[Py][Px] = '.';
                        }
                    }
                }
            }
        }

        if (Exploded)
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