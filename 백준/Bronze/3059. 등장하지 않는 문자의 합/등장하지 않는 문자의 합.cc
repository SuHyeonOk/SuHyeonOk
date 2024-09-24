#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    bool arr[26]{ false };
    string Input = "";
    while (T--)
    {
        cin >> Input;

        size_t Length = Input.length();
        for (size_t i = 0; i < Length; ++i)
        {
            arr[Input[i] - 'A'] = true;
        }

        int Result = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (false == arr[i])
            {
                Result += i + 'A';
            }
        }
        cout <<  Result << '\n';
        memset(arr, 0, sizeof(arr));
    }

    return 0;
}