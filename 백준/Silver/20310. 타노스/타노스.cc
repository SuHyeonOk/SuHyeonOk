#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Str = "";
    cin >> Str;

    int Zero = 0;
    int One = 0;

    size_t Length = Str.length();
    for (size_t i = 0; i < Length; i++)
    {
        if ('0' == Str[i])
        {
            ++Zero;
        }
        else
        {
            ++One;
        }
    }

    for (int i = 0; i < Zero / 2; i++)
    {
        cout << 0;
    }
    for (int i = 0; i < One / 2; i++)
    {
        cout << 1;
    }

    return 0;
}