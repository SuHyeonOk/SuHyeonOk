#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    string Str = "";
    int Count = 0;
    for (int i = 3; i <= N; ++i)
    {
        Str = to_string(i);
        int Length = Str.length();
        for (int j = 0; j < Length; ++j)
        {
            if ('3' == Str[j] || '6' == Str[j] || '9' == Str[j])
            {
                ++Count;
            }
        }
    }
    cout << Count;

    return 0;
}