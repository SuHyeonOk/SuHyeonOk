#include <iostream>
#define MAX 45 // 1000이 넘어가는 경우의 최댓값
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int arr[MAX + 1]{ 0 };
    for (int i = 1; i <= MAX; i++)
    {
        arr[i] = (i * (i + 1)) / 2;
    }

    while(T--)
    {
        int N = 0;
        cin >> N;

        bool Find = false;
        for (int i = 1; i < MAX; i++)
        {
            for (int j = 1; j < MAX; j++)
            {
                for (int k = 1; k < MAX; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == N) 
                    {
                        Find = true;
                        break;
                    }
                }

                if (true == Find)
                {
                    break;
                }
            }

            if (true == Find)
            {
                break;
            }
        }

        cout << Find << "\n";
    }

    return 0;
}