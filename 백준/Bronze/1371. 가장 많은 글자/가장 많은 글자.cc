#include <iostream>
#include <cctype>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[26]{ 0 };

    char c = ' ';
    int Max = 0;
    while (cin >> noskipws >> c) // EOF까지 입력 받음
    { 
        if (isalpha(c))
        {
            Max = max(Max, ++arr[c - 'a']);
        }
    }

    for (int i = 0; i < 26; ++i) 
    {
        if (arr[i] == Max) 
        {
            cout << (char)(i + 'a');
        }
    }

    return 0;
}