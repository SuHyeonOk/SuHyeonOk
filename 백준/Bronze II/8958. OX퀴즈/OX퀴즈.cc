#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int TestCase = 0;
    cin >> TestCase;

    int Sum = 0;
    int Count = 0;
    while (TestCase--)
    {
        string Input = "";
        cin >> Input;

        size_t Size = Input.size();
        for (size_t i = 0; i < Size; i++)
        {
            if (Input[i] == 'O')
            {
                ++Count;
                Sum += Count;
            }
            else if (Input[i] == 'X')
            {
                Count = 0;
            }
        }
        cout << Sum << '\n';
        Sum = 0;
        Count = 0;
    }

    return 0;
}