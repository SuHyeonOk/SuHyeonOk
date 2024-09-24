#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    bool Find = false;
    int Count = 0, Width = 0;
    char arr[100][100];

    for (int i = 0; i < N; ++i)
    {
        Count = 0;
        Find = false;

        for (int j = 0; j < N; ++j) // 입력과 동시에 가로에 누울 수 있는 자리 계산
        {
            cin >> arr[i][j];

            if ('.' == arr[i][j])
            {
                ++Count;

                if (false == Find && 2 <= Count)
                {
                    Find = true;
                    ++Width;
                }
            }
            else
            {
                Find = false;
                Count = 0;
            }
        }
    }

    int Length = 0;
    for (int i = 0; i < N; ++i)
    {
        Count = 0;
        Find = false;

        for (int j = 0; j < N; ++j) // 세로 자리 계산
        {
            if ('.' == arr[j][i])
            {
                ++Count;

                if (false == Find && 2 <= Count)
                {
                    Find = true;
                    ++Length;
                }
            }
            else
            {
                Find = false;
                Count = 0;
            }
        }
    }

    cout << Width << ' ' << Length;

    return 0;
}