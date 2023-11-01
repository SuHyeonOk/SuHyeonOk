#include <iostream>
using namespace std;
#define MAX 10000

int arr[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 }, M{ 0 };
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int start{ 0 }, end{ 0 }, sum{ arr[0] }, answer{ 0 };

    while (end < N)
    {
        if (sum < M)
        {
            ++end;

            if (end < N)
            {
                sum += arr[end];
            }
        }
        else if (sum > M)
        {
            sum -= arr[start];
            ++start;
        }
        else if (sum == M)
        {
            sum -= arr[start];
            ++start;
            ++end;
            ++answer;

            if (end < N)
            {
                sum += arr[end];
            }
        }
    }

    cout << answer;

    return 0;
}