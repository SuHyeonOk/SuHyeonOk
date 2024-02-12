#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 }, M{ 0 }, result{ 0 };
    string str{ "" };
    cin >> N >> M >> str;

    for (int i = 1; i < M; i++)
    {
        int cnt{ 0 };
        if (str[i - 1] == 'I')
        {
            while (str[i] == 'O' && str[i + 1] == 'I')
            {
                i += 2;
                cnt++;
                if (cnt == N)
                {
                    cnt--;
                    result++;
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}