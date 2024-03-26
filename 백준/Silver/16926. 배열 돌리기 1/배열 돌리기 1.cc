#include <iostream>
#include <algorithm>
#define MAX 301
using namespace std;

int N, M, R;
int arr[MAX][MAX];

void Rotation() 
{
    int temp[MAX][MAX];

    for (int rot = 0; rot < min(N, M) / 2; rot++) 
    {
        int x1 = rot, y1 = rot, x2 = N - 1 - rot, y2 = M - 1 - rot;
        
        for (int i = y2 - 1; i >= y1; i--)
        {
            temp[x1][i] = arr[x1][i + 1];
        }
        
        for (int i = x1 + 1; i <= x2; i++)
        {
            temp[i][y1] = arr[i - 1][y1];
        }

        for (int i = y1 + 1; i <= y2; i++)
        {
            temp[x2][i] = arr[x2][i - 1];
        }

        for (int i = x2 - 1; i >= x1; i--) 
        {
            temp[i][y2] = arr[i + 1][y2];
        }
    } 

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            arr[i][j] = temp[i][j];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> R;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> arr[y][x];
        }
    }

    while (R--)
    {
        Rotation();
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cout << arr[y][x] << ' ';
        }
        cout << '\n';
    }

    return 0;
}