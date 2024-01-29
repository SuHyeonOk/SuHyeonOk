#include <iostream>
#define MAX 3
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[MAX];
    for (size_t i = 0; i < MAX; i++)
    {
        cin >> arr[i];
    }

    if (arr[0] == 60 && arr[1] == 60 && arr[2] == 60) // 세 각의 크기가 모두 60이면
    {
        cout << "Equilateral";
        return 0;
    }
    
    if (arr[0] + arr[1] + arr[2] == 180) // 세 각의 합이 180이고
    {
        if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]) // 두 각이 같은 경우
        {
            cout << "Isosceles";
        }
        else
        {
            cout << "Scalene";
        }
    }
    else
    {
        cout << "Error";
    }

    return 0;
}