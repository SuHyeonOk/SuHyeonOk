#include <iostream>
using namespace std;

bool arr[2000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, C = 0;
    cin >> N >> C;

    int Input = 0, Count = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;

        for (int j = Input; j <= C; j += Input)
        {
            if (arr[j] == false)
            {
                arr[j] = true;
                ++Count;
            }
        }
    }

    cout << Count;

    return 0;
}
