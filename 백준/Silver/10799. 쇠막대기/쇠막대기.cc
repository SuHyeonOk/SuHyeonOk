#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str{ "" };
    cin >> str;

    int bar{ 0 }, result{ 0 };
    size_t size = str.size();
    for (size_t i = 0; i < size; ++i)
    {
        if (str[i] == '(' && str[i + 1] == ')')
        {
            // 레이저
            result += bar;
            ++i;
            continue;
        }

        if (str[i] == '(')
        {
            ++bar;
            ++result;
        }
        else // )
        {
            --bar;
        }
    }

    cout << result;

    return 0;
}