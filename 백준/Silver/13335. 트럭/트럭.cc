#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = 0, w = 0, l = 0;
    cin >> n >> w >> l;

    int arr[1000]{ 0, };
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    queue<int> q;

    int Sum = 0, Time = 0;
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            if (w == q.size()) // 트럭 개수
            {
                Sum -= q.front();
                q.pop();
            }

            if (arr[i] + Sum <= l)
            {
                break; // 트럭 지나갈 수 있는 무게
            }

            q.push(0);
            ++Time;
        }

        q.push(arr[i]);
        Sum += arr[i];
        ++Time;
    }

    cout << Time + w;

    return 0;
}