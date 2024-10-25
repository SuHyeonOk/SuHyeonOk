#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    int Input = 0, Count = 0;
    bool arr[100]{ false };
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        if (false == arr[Input])
        {
            arr[Input] = true;
        }
        else
        {
            ++Count;
        }
    }

    cout << Count;

    return 0;
}