#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_TIME 640000000
int N, M, B, x;
int blocks[256 + 1];
int ans[2];
int main()
{
    cin >> N >> M >> B;

    int total = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> x;
            total += x;
            for (int k = 1; k <= x; k++)
                blocks[k]++;
        }
    }

    ans[0] = MAX_TIME;

    for (int i = 0; i <= 256; i++)
    {
        int time = 0;      
        int height = i;   
        int inventory = B; 

        // 채우기
        for (int j = 1; j <= i; j++)
        {
            inventory -= N * M - blocks[j];
            time += N * M - blocks[j];
        }

        // 고르기
        for (int j = i + 1; j <= 256; j++)
        {
            inventory += blocks[j];
            time += blocks[j] * 2;
        }
        if (inventory < 0)
            break;

        if (ans[0] >= time)
        {
            ans[0] = time;
            ans[1] = height;
        }
    }

    cout << ans[0] << " " << ans[1] << '\n';
}