#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int TestCase = 0;
    cin >> TestCase;

    while (TestCase--)
    {
        string Str = " ";
        cin >> Str;

        int Count = 0;
        size_t Size = Str.size();
        for (size_t i = 0; i < Size; i++)
        {
            if (Str[i] == '(')
            {
                ++Count;
            }
            else
            {
                --Count;
                if (Count < 0)
                {
                    cout << "NO" << '\n';
                    Str = "NO";
                    break;
                }
            }
        }

        if (Str == "NO")
        {
            continue;
        }
        else if(Count == 0)
        {
            cout << "YES" << '\n';
        }
        else if(Count != 0)
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}