#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin >> N;

    vector<int> vec(N);
    for (int i = 1; i <= N; i++) 
    {
        int Temp = 0;
        cin >> Temp;

        for (int j = 0; j < N; j++) 
        {
            if (Temp == 0 && vec[j] == 0) 
            {
                vec[j] = i;
                break;
            }
            if (vec[j] == 0) 
            {
                Temp--;
            }
        }
    }

    for (int i = 0; i < N; i++) 
    {
        cout << vec[i] << " ";
    }

    return 0;
}