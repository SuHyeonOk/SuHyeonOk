#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
    int N = 0;
    cin >> N;

    string arr[50];
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int Count = N;
    for (int i = 0; i < N; i++) 
    {
        string Temp = arr[i + 1].substr(0, arr[i].size());
        if (Temp == arr[i])
        {
            Count--;
        }
    }
    cout << Count;

    return 0;
}