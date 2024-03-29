#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int TestCase = 0;
    cin >> TestCase;
    cin.ignore();

    string Str = "", Temp = "", Result = "";
    while(TestCase--)
    {
        getline(cin, Str);
      
        size_t Length = Str.length();
        for (size_t i = 0; i < Length; i++)
        {
            if (' ' == Str[i]) // 공백
            {
                reverse(Temp.begin(), Temp.end());
                Result += Temp;
                Result += ' ';
                Temp = "";
            }
            else // 문자
            {
                Temp += Str[i];
            }
        }
    
        reverse(Temp.begin(), Temp.end());
        Result += Temp;

        cout << Result << '\n';

        Result = "";
        Temp = "";
    }

    return 0;
}