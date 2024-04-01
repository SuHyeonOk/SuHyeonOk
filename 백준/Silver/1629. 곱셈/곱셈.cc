#include <iostream>
#include <cmath>
using namespace std;

long long Pow(long long a, long long b, long long c)
{
    if (b == 0)
    {
        return 1;
    }

    long long temp;
    temp = Pow(a, b / 2, c); // 지수를 절반 나눠서 재귀 호출
    temp = temp * temp % c; // c로 나눈 나머지를 temp에 저장
    
    if (b % 2 == 0) // 짝수
    {
        return temp;
    }
    else // 홀수일 경우 a를 곱해서 다시 c로 나눠줌
    {
        return temp * a % c;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;
    cout << Pow(A, B, C);

    return 0;
}