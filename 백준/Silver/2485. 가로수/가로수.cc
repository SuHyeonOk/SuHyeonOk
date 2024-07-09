#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int arr[MAX];
int dis[MAX];

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    
    // 가로수 사이 간격
    for (int i = 0; i < N - 1; i++)
    {
        dis[i] = arr[i + 1] - arr[i];
    }

    // 가로수 간격의 최대공약수
    int Gcd = dis[0];
    for (int i = 1; i < N - 1; i++)
    {
        Gcd = GCD(Gcd, dis[i]);
    }

    // 추가로 심는 가로수
    int Count = 0;
    for (int i = 0; i < N - 1; i++)
    {
        Count += (dis[i] / Gcd) - 1;
    }

    cout << Count;

    return 0;
}