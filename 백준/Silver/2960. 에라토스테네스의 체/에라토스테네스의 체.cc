#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, K = 0;
    cin >> N >> K;

    bool visited[1001]{ false }; 
    for (int i = 2; i <= N; ++i)
    {
        if (true == visited[i])
        {
            continue;
        }

        for (int j = i; j <= N; j += i)
        {
            if (false == visited[j])
            {
                visited[j] = true;
                --K;

                if (K == 0)
                {
                    cout << j;
                    return 0;
                }
            }
        }
    }

    return 0;
}