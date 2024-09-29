#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Input = "";
    while (true)
    {
        cin >> Input;

        if (Input == "end")
        {
            break;
        }

        int Vowel = 0, Consonant = 0; // 모음 자음
        bool Find = false;
        char Temp = ' ';
        string Print = "is acceptable.";
        size_t Length = Input.length();
        for (size_t i = 0; i < Length; ++i)
        {
            if (Vowel >= 3 || Consonant >= 3 || Temp == Input[i])
            {
                Print = "is not acceptable.";
                break;
            }

            if (Input[i] == 'e' || Input[i] == 'o' || Input[i] == 'a' || Input[i] == 'i' || Input[i] == 'u')
            {
                if (Length >= i + 1 && Input[i + 1] == 'e' || Input[i + 1] == 'o')
                {
                    ++i;
                    ++Vowel;
                }
                Find = true;
                Consonant = 0;
                ++Vowel;
            }
            else
            {
                Vowel = 0;
                ++Consonant;
            }

            Temp = Input[i];
            if (Temp == 'e' || Temp == 'o')
            {
                Temp = ' ';
            }
        }

        if (false == Find || Vowel >= 3 || Consonant >= 3)
        {
            Print = "is not acceptable.";
        }

        cout << '<' << Input << "> " << Print << '\n';
    }

    return 0;
}