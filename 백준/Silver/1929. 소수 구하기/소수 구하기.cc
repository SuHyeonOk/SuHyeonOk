#include<iostream>

using namespace std;

// static overflow가 발생하기 때문에 Data영역에 저장될 수 있도록 전역 변수로 선언한다.
int arr[1000001]{ 0 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        for (int j = i * i; j <= n; j += i)
        {
            arr[j] = 0;
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (arr[i] != 0)
        {
            cout << arr[i] << '\n';
        }
    }

    return 0;
}