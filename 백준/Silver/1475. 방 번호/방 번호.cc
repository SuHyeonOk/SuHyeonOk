#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str{ "" };
    cin >> str;

    int arr[10]{ 0 };

    size_t length{ str.length() };
    for (size_t i = 0; i < length; i++)
    {
        ++arr[str[i] - '0'];
    }

    int maxnum{ arr[6] + arr[9] };

    if (0 != maxnum % 2) // 홀수인 경우
    {
        maxnum *= 0.5;
        maxnum += 1;
    }
    else
    {
        maxnum *= 0.5;
    }

    for (int i = 0; i < 9; i++) // 0~8 그중 6도 제외
    {
        if (i == 6)
        {
            continue;
        }

        maxnum = max(maxnum, arr[i]);
    }
    
    cout << maxnum;

    return 0;
}