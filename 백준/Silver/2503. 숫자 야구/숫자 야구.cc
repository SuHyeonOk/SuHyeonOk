#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool visited[1001]{ false };
    memset(visited, true, sizeof(visited));

    // 세 자리 수가 될 수 없는 경우를 false 처리한다.
    string Temp = "";
    for (int i = 123; i <= 987; i++) 
    {
        Temp = to_string(i);

        if (Temp[0] - '0' == 0 || Temp[1] - '0' == 0 || Temp[2] - '0' == 0)
        {
            visited[i] = false; // 0이 들어간 경우 false
        }
        if (Temp[0] == Temp[1] || Temp[1] == Temp[2] || Temp[0] == Temp[2])
        {
            visited[i] = false; // 동일한 숫자가 쓰이는 경우 false
        }
    }

    int N = 0;
    cin >> N;

    string Case1 = "", Case2 = "";
    int StrikeCount = 0, BallCount = 0, Count = 0; 
    int Number = 0, Strike = 0, Ball = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> Number >> Strike >> Ball;

        for (int j = 123; j <= 987; j++) 
        {
            StrikeCount = 0;
            BallCount = 0;

            if (true == visited[j]) 
            {
                Case1 = to_string(Number);
                Case2 = to_string(j);

                for (int a = 0; a < 3; a++) 
                {
                    for (int b = 0; b < 3; b++) 
                    {
                        if (a == b && Case1[a] == Case2[b])
                        {
                            StrikeCount++;
                        }
                        if (a != b && Case1[a] == Case2[b])
                        {
                            BallCount++;
                        }
                    }
                }

                if (StrikeCount != Strike || BallCount != Ball)
                {
                    visited[j] = false;
                }
            }
        }
    }

    for (int i = 123; i <= 987; i++) 
    {
        if (true == visited[i])
        {
            Count++;
        }
    }
    cout << Count;

    return 0;
}