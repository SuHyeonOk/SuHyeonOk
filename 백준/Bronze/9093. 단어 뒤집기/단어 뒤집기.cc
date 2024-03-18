#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    cin >> T;
    cin.ignore(); // 입력 버퍼 비우기 (T 입력 후 남은 '\n' 제거)

    stack<char> Ss;

    while (T--)
    {
        string str;
        getline(cin, str);  // 한 줄 읽어오기
        str += ' '; // 마지막 확인용

        for (int i = 0; i < str.length(); i++) 
        {
            if (str[i] == ' ') 
            {
                while (false == Ss.empty()) 
                {
                    cout << Ss.top();
                    Ss.pop();
                }
                cout << ' ';
            }
            else
            {
                Ss.push(str[i]);  // 공백 아닐 경우 push
            }
        }
        cout << "\n";
    }

    return 0;
}