#include <iostream>
#define MAX 1000
using namespace std;

int main() 
{
    int A = 0, B = 0;
    cin >> A >> B;

    int arr[MAX + 1]{ 0, };
    int Index = 0, i = 0;
    while (Index <= B)
    {
        ++i;
        for (int j = 0; j < i; j++)
        {
            arr[Index++] = i;

            if (Index > B)
            {
                break;
            }
        }
    }

    int Sum = 0;
    for (int i = A - 1; i < B; i++)
    {
        Sum += arr[i];
    }
    cout << Sum;

    return 0;
}
