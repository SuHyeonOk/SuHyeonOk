#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;

    // 소수점 둘째 짜리 고정.
    cout << fixed;
    cout.precision(2);


    // @는 3을 곱하고, %는 5를 더하며, #는 7을 빼
    float Result = 1.f;
    string Input = "";
    while (T--)
    {
        cin >> Result;
        getline(cin, Input);

        size_t Size = Input.size();
        for (size_t i = 0; i < Size; ++i)
        {
            if ('@' == Input[i])
            {
                Result *= 3;
            }
            else if ('%' == Input[i])
            {
                Result += 5;
            }
            else if ('#' == Input[i])
            {
                Result -= 7;
            }
        }

        cout << Result << '\n';
    }


    return 0;
}