#include <iostream>
using namespace std;

int R, C, K;
char arr[5][5];

int Count;
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };
bool visited[5][5];

void Backtracking(int _Depth, int _X, int _Y)
{
    if (_Depth == K)
    {
        if (_X == C - 1 && _Y == 0)
        {
            ++Count;
        }
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int NX = _X + dx[i];
        int NY = _Y + dy[i];

        if (0 > NX || C <= NX || 0 > NY || R <= NY)
        {
            continue;
        }

        if (true == visited[NY][NX] || 'T' == arr[NY][NX])
        {
            continue;
        }

        visited[NY][NX] = true;
        Backtracking(_Depth + 1, NX, NY);
        visited[NY][NX] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> K;

    for (int y = 0; y < R; ++y)
    {
        for (int x = 0; x < C; ++x)
        {
            cin >> arr[y][x];
        }
    }

    visited[R - 1][0] = true;
    Backtracking(1, 0, R - 1);
    cout << Count;

    return 0;
}