#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Input = "";
    cin >> Input;
    size_t Length = Input.length();

    int A[26]{ ' ' };
    int B[26]{ ' ' };

    for (size_t i = 0; i < Length; ++i)
    {
        ++A[Input[i] - 'a'];
    }

    cin >> Input;
    Length = Input.length();
    for (size_t i = 0; i < Length; ++i)
    {
        ++B[Input[i] - 'a'];
    }

    int Count = 0;
    for (int i = 0; i < 26; ++i)
    {
        Count += abs(A[i] - B[i]);
    }

    cout << Count;

    return 0;
}