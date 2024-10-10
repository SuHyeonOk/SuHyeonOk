#include <iostream>
using namespace std;

bool visited[2000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, C = 0;
    cin >> N >> C;

    int Input = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;

        if (false == visited[Input])
        {
            for (int j = Input; j <= C; j += Input)
            {
                visited[j] = true;
            }
        }
    }

    int Count = 0;
    for (int i = 1; i <= C; ++i)
    {
        if (visited[i] == true)
        {
            ++Count;
        }
    }

    cout << Count;

    return 0;
}
