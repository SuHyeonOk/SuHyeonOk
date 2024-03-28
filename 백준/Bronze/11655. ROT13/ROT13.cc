#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str = "";
    getline(cin, str);

    size_t Size = str.size();
    for (size_t i = 0; i < Size; i++)
    {
        if (str[i] == ' ' || str[i] < 64)
        {
            continue;
        }

        int Temp = static_cast<int>(str[i]);
        
        if (Temp < 91) // 대문자
        {
            if (Temp + 13 > 90)
            {
                int Ans = Temp + 13 - 90;
                str[i] = static_cast<char>(64 + Ans);
            }
            else
            {
                str[i] = static_cast<char>(Temp + 13);
            }
        }
        else // 소문자
        {
            if (str[i] == 'n')
            {
                int a = 0;
            }

            if (Temp + 13 > 122)
            {
                int Ans = Temp + 13 - 122;
                str[i] = static_cast<char>(96 + Ans );
            }
            else
            {
                str[i] = static_cast<char>(Temp + 13);
            }
        }
    }

    cout << str;

    return 0;
}