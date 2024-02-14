#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;
    
    int arr[26] = { 0, };
    int Count = 0;
    for (int i = 0; i < N; i++)
    {
        fill(arr, arr + 26, 0);
     
        string Input = "";
        cin >> Input;

        char Temp = ' ';
        size_t Size = Input.size();
        for (size_t j = 0; j < Size; j++)
        {
            if (Temp != Input[j] && arr[Input[j] - 'a'] != 0)
            {
                --Count;
                break;
            }
            ++arr[Input[j] - 'a'];
            Temp = Input[j];
        }
        ++Count;
    }

    cout << Count;

    return 0;
}