#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string Input = "";

    while (getline(cin, Input))
    {
        int A = 0, B = 0, C = 0, D = 0;
        size_t Length = Input.length();

        for (size_t i = 0; i < Length; ++i)
        {
            if (Input[i] >= 'a' && Input[i] <= 'z')
            {
                ++A;
            }
            else if (Input[i] >= 'A' && Input[i] <= 'Z')
            {
                ++B;
            }
            else if (Input[i] - '0' >= 0 && Input[i] - '0' <= 9)
            {
                ++C;
            }
            else // 공백
            {
                ++D;
            }
        }

        cout << A << ' ' << B << ' ' << C << ' ' << D << '\n';

    }

    return 0;
}