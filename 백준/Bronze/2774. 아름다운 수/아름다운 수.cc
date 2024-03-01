#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    while (T--)
    {
        string Input = "";
        cin >> Input;

        int arr[10]{ 0 };
        size_t Size = Input.length();
        for (size_t i = 0; i < Size; i++)
        {
            ++arr[Input[i] - '0'];
        }

        size_t Count = 0;
        for (size_t i = 0; i < 10; i++)
        {
            if (arr[i] != 0)
            {
                ++Count;
            }
        }

        cout << Count << '\n';
    }


    return 0;
}