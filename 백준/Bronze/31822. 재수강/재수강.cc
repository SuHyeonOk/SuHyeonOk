#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string MyString = "";
    cin >> MyString;

    MyString = MyString.substr(0, 5);
    int MyInt = stoi(MyString);
    
    int N = 0;
    cin >> N;

    string Input = "";
    int Count = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> Input;
        Input = Input.substr(0, 5);

        if (stoi(Input) == MyInt)
        {
            ++Count;
        }
    }

    cout << Count;

    return 0;
}