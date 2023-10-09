#include <iostream>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 };
    cin >> N;

    if (N < 100) // 100보다 작은 경우는 등차 수열 개수 N개
    {
        cout << N;
        return 0;
    }
    
    // 나머지 100~999까지의 등차수열 구하기
    int sum{ 99 };
    for (int i = 100; i <= N; i++)
    {
        int a = i / 100; // 첫번째 자리 수
        int b = (i / 10) % 10; // 두번째 자리 수
        int c = i % 10; // 세번째 자리 수

        if ((a - b) == (b - c))
        {
            ++sum;
        }
    }

    cout << sum;

    return 0;
}