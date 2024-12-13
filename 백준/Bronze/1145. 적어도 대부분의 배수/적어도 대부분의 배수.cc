#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[5]{ 0 };
    for (int& ele : arr)
    {
        cin >> ele;
    }

    for (int i = 1; i < 1000000; i++)
    {
        int Count = 0;
        for (int j = 0; j < 5; j++)
        {
            if (i % arr[j] == 0)
            {
                Count++;
            }
        }

        if (Count >= 3)
        {
            cout << i;
            break;
        }
    }

    return 0;
}