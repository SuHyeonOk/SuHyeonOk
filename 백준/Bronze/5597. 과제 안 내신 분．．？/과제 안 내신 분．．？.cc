#include <iostream>
using namespace std;
#define MAX 31

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool arr[MAX]{ false };
    int input{ 0 };

    for (int i = 0; i < 28; i++)
    {
        cin >> input;
        arr[input] = true;
    }

    for (int i = 1; i < MAX; i++)
    {
        if (false == arr[i])
        {
            cout << i << '\n';
        }
    }
    
    return 0;
}