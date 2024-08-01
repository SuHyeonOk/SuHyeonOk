#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    vector<int> vec;
    while (true)
    {
        cin >> N;

        if (-1 == N)
        {
            break;
        }

        int Sum = 0;
        for (int i = 1; i < N; ++i)
        {
            if (N % i == 0) // 약수 조건 해당
            {
                vec.push_back(i);
                Sum += i;
            }
        }

        if (Sum == N)
        {
            cout << N << " = ";
            size_t Size = vec.size() - 1; // N 제외
            for (size_t i = 0; i < Size; ++i)
            {
                cout << vec[i] << " + ";
            }
            cout << vec[Size] << '\n';
        }
        else
        {
            cout << N << " is NOT perfect." << '\n';
        }

        vec.clear();
    }

    return 0;
}