#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    int arr[26]{ 0 };
    string Input = "";
    while (T--)
    {
        cin >> Input;

        size_t Length = Input.length();
        for (size_t i = 0; i < Length; ++i)
        {
            arr[Input[i] - 'A'] = static_cast<int>(Input[i]);
        }

        int Result = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (0 != arr[i])
            {
                Result += arr[i];
            }
        }
        cout << 2015 - Result << '\n';
        memset(arr, 0, sizeof(arr));
    }

    return 0;
}