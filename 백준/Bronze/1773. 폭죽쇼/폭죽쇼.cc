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

        int j = 1, Temp = Input;
        while (Temp <= C)
        {
            if (false == arr[Input * j])
            {
                arr[Input * j] = true;
                ++Count;
            }
            ++j;
            Temp = Input;
            Temp *= j;
        }

    }

    cout << Count;

    return 0;
}