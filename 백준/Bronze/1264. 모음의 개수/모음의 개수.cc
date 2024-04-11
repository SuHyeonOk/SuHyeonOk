#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Str = "";
    int Count = 0;

    while (true)
    {
        getline(cin, Str);

        if (Str == "#")
        {
            break;
        }

        size_t Length = Str.length();
        for (size_t i = 0; i < Length; i++)
        {
            if (Str[i] == 'a' || Str[i] == 'e' || Str[i] == 'i' || Str[i] == 'o' || Str[i] == 'u' ||
                Str[i] == 'A' || Str[i] == 'E' || Str[i] == 'I' || Str[i] == 'O' || Str[i] == 'U')
            {
                ++Count;
            }
        }

        cout << Count << '\n';
        Count = 0;
    }

    return 0;
}