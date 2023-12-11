#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N{ 1 }, M{ 1 };
vector<int> vecN{ 0 };
vector<int> vecM{ 0 };

bool Binary(int _target)
{
    int left{ 0 }, right{ N }, mid{ 0 }, result{ 0 };

    while (left <= right)
    {
        mid = (left + right) * 0.5;

        if (vecM[mid] == _target)
        {
            return true;
        }
        else if (vecM[mid] > _target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true)
    {
        cin >> N >> M;

        if (N == 0 && M == 0)
        {
            break;
        }

        vecN.resize(N);
        for (int i = 0; i < N; i++)
        {
            cin >> vecN[i];
        }

        vecM.resize(M);
        for (int i = 0; i < M; i++)
        {
            cin >> vecM[i];
        }

        // 상근(N)이가 가지고 있는 CD를 기준으로 선영(M)가 CD를 가지고 있는지 확인한다.
        int count{ 0 };
        for (int i = 0; i < N; i++)
        {
            bool find = Binary(vecN[i]);
            //bool find = binary_search(vecM.begin(), vecM.end(), vecN[i]);

            if (true == find)
            {
                ++count;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
