#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long arr[100001];

int main() 
{
    unsigned long long n{ 0 }, m{ 0 };
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    unsigned long long right = { m * arr[0] };
    // 심사 시간이 제일 적은 데스크에 모든 사람이 검사 받는 경우를 최대 값으로 잡아줌
    unsigned long long left{ 1 };
    unsigned long long mid{ 0 };
    unsigned long long ans{ 0 };
    unsigned long long people{ 0 };

    while (left <= right)
    {
        people = 0;
        mid = (right + left) / 2;

        for (int i = 0; i < n; i++) 
        {
            people += mid / arr[i]; // mid시간에 검사할 수 있는 인원 수
        }

        if (people >= m) 
        { 
            // 검사 인원이 주어진 인원이랑 같거나 커야 조건 만족
            if (ans > mid || ans == 0) 
            {
                // 최소시간일때 답 저장
                ans = mid;
            }
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
