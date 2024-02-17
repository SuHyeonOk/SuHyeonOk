#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Input = "";
    cin >> Input;

    size_t Size = Input.size() + 1;
    for (size_t i = 1; i < Size; i++)
    {
        cout << Input[i - 1];
        if(i % 10 == 0)
        {
            cout << '\n';
        }
    }

    return 0;
}