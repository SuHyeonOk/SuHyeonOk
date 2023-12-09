#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    pair<int, int> arr[100000];
    int T{ 0 };
    cin >> T;

    while (T--)
    {
        int N{ 0 };
        cin >> N;

        for (int i = 0; i < N; i++) // 모든 점수 입력 받기
        {
            cin >> arr[i].first >> arr[i].second;
        }

        sort(arr, arr + N);

        int result{ 1 }; // 신입  사원은 1명 이상 즉, 1등은 반드시 존재 하기에 1부터 센다.
        int bsetScore{ arr[0].second }; // 서류 1등의 면접 등수

        for (int i = 1; i < N; i++)
        {
            if (bsetScore > arr[i].second)
            {
                ++result;
                bsetScore = arr[i].second; // 서류 1등의 면접 등수보다 좋은 사람의 등수 갱신
            }
        }

        cout << result << '\n';
    }

    return 0;
}