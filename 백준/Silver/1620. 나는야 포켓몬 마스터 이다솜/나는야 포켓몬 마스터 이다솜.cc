#include <iostream>
#include <unordered_map>
#include <cctype>  // isalpha, isdigit 함수를 사용하기 위한 헤더
#include <string> // stoi 함수를 사용하기 위한 헤더
using namespace std;

// 문자열이 영문자로만 이루어져 있는지 확인하는 함수
bool isAlpha(const string& str) 
{
    for (char ch : str) 
    {
        // isalpha 함수를 사용하여 각 문자가 영문자인지 확인
        if (false == isalpha(static_cast<unsigned char>(ch))) 
        {
            return false; // 영문자가 아닌 경우 false 반환
        }
    }
    return true; // 모든 문자가 영문자인 경우 true 반환
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0, M = 0;
    cin >> N >> M;

    string str = "";
    unordered_map<string, int> name;
    unordered_map<int, string> number;

    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        name[str] = i;
        number[i] = str;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> str;
        if (true == isAlpha(str)) // 문자열
        {
            cout << name[str] << '\n';
        }
        else // 숫자
        {
            cout << number[stoi(str)] << '\n';
        }
    }

    return 0;
}