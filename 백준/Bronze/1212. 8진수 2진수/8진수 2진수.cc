#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str = "";
    cin >> str;

    string arr[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
    
    int temp = 0;
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        temp = str[i] - '0';
        if (i == 0)
        {
            cout << stoi(arr[temp]); // string to int
        }
        else
        {
            cout << arr[temp];
        }
    }

    return 0;
}