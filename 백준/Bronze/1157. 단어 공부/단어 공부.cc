#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string Str = "";
    cin >> Str;

    int arr[26]{ 0, };
    size_t Length= Str.length();
    for (size_t i = 0; i < Length; i++)
    {
        int Temp = static_cast<int>(Str[i]);
        if (Temp > 90) // 문자가 소문자인 경우 소문자 숫자로 변경
        {
            Temp -= 32;
        }
        ++arr[Temp - 65];
    }

    int MaxIndex = 0;
    int MaxCount = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if (MaxCount < arr[i])
        {
            MaxIndex = i;
            MaxCount = arr[i];
        }
    }

    bool Find = false;
    for (size_t i = 0; i < 26; i++)
    {
        if (MaxCount == arr[i])
        {
            if (false == Find)
            {
                Find = true;
            }
            else
            {
                cout << '?'; // 이전에 MaxIndex가 있었는데 또 발견된 경우 많이 사용된 알파벳이 여러개인 경우이다.
                return 0;
            }
        }
    }

    cout << static_cast<char>(MaxIndex += 65);

    return 0;
}