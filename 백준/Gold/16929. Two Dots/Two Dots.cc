#include <iostream>
#include <string.h>
using namespace std;

int Y, X; // N M
char arr[50][50];
bool visited[50][50];
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

bool Find;
char Color;
int StartX, StartY;
void DFS(int _Y, int _X, int _Depth)
{
    for (int i = 0; i < 4; ++i)
    {
        int NX = _X + dx[i];
        int NY = _Y + dy[i];

        if (_Depth >= 3 && NY == StartY && NX == StartX)
        {
            Find = true;
            return;
        }

        if (0 > NY || Y <= NY || 0 > NX || X <= NX)
        {
            continue;
        }

        if (true == visited[NY][NX] || Color != arr[NY][NX])
        {
            continue;
        }

        visited[NY][NX] = true;
        DFS(NY, NX, _Depth + 1);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> Y >> X;

    for (int y = 0; y < Y; ++y)
    {
        for (int x = 0; x < X; ++x)
        {
            cin >> arr[y][x];
        }
    }

    for (int y = 0; y < Y; ++y)
    {
        for (int x = 0; x < X; ++x)
        {
            Color = arr[y][x];
            visited[y][x] = true;
            StartY = y;
            StartX = x;
            DFS(y, x, 0);
            memset(visited, false, sizeof(visited));

            if (true == Find)
            {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    return 0;
}