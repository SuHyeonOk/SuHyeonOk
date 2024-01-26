#include <iostream>
#define MAX 8
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int Count = 0;
    char chessboard[MAX][MAX];

    for (size_t y = 0; y < MAX; y++)
    {
        for (size_t x = 0; x < MAX; x++)
        {
            cin >> chessboard[y][x];
        
            if (y % 2 != 0 && x % 2 != 0 && chessboard[y][x] == 'F')
            {
                ++Count;
            }
            else if (y % 2 == 0 && x % 2 == 0 && chessboard[y][x] == 'F')
            {
                ++Count;
            }
        }
    }

    cout << Count;

    return 0;
}