#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Str = "";
    cin >> Str;

    string Result = "";
    size_t Size = Str.size();
    for (size_t i = 0; i < Size; i++)
    {
        int Temp = static_cast<int>(Str[i]);
        if (65 <= Temp && 90 >= Temp)
        {
            Result += Str[i];
        }
    }

    cout << Result;

    return 0;
}