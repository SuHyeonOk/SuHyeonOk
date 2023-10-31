#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str{ "" };
    cin >> str;

    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (96 > str[i]) // 대문자
        {
            str[i] += 32;
        }
        else // 소문자
        {
            str[i] -= 32;
        }
    }

    cout << str;

    return 0;
}