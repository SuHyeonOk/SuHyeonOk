#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string str; 
    cin >> str;

    while (str.length() % 3 != 0) // 입력 받은 문자열 길이가 3으로 나눠 떨어지지 않으면,
    {
        str = '0' + str; // 첫번째 자리에 0이 제외된 상태이다.
    }

    for (size_t i = 0; i < str.length(); i += 3)
    {   // i = 0, 3, 6, ,,
        int num = (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0');
        cout << num;
    }

    return 0;
}