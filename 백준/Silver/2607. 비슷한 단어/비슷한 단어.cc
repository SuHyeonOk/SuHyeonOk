#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    string CompariWord = "";
    cin >> CompariWord;
    
    // 비교 대상 문자열
    size_t CompariLength = CompariWord.length();
    int alpha[26]{ 0, };
    for (size_t i = 0; i < CompariLength; i++)
    {
        alpha[CompariWord[i] - 65] += 1;
    }

    string TempWord = "";
    size_t TempLength = 0;

    size_t SameNumber = 0;
    size_t Result = 0;

    --N;
    for (int i = 0; i < N; i++)
    {
        cin >> TempWord;
        TempLength = TempWord.length();
       
        SameNumber = 0;

        int tempAlpha[26]{ 0, };
        copy(alpha, alpha + 26, tempAlpha);
        for (size_t j = 0; j < TempLength; j++)
        {
            if (true == tempAlpha[TempWord[j] - 65] > 0)
            {
                --tempAlpha[TempWord[j] - 65];
                ++SameNumber;
            }
        }

        if (CompariLength == TempLength)
        {
            if (SameNumber == CompariLength || SameNumber == TempLength - 1)
            {
                ++Result; // 구성이 같거나, 한글자만 다른 경우
            }
        }
        else if (CompariLength - 1 == TempLength && SameNumber == CompariLength - 1)
        {
            ++Result; // 첫째줄 문자열이 하나 더 길 때 = 한 글자 추가
        }
        else if (CompariLength + 1 == TempLength && SameNumber == CompariLength)
        {
            ++Result;
        }
    }
    
    cout << Result;

    return 0;
}