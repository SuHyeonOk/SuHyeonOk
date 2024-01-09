#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long N{ 0 }, M{ 0 }, iMax{ 0 };
    cin >> N >> M;

    vector<long long> vec;
    vec.resize(N);

    for (long long i = 0; i < N; i++)
    {
        cin >> vec[i];
        iMax = max(iMax, vec[i]);
    }

    long long iLeft{ 1 }, iRight{ iMax }, iPivot{ 0 }, iReault{ 0 };

    while (iLeft <= iRight)
    {
        iPivot = (iLeft + iRight) / 2;

        long long iTarget{ 0 };
        for (long long i = 0; i < N; i++)
        {
            iTarget += (vec[i] > iPivot) ? vec[i] - iPivot : 0;
        }

        if (iTarget < M)
        {
            iRight = iPivot - 1;
        }
        else
        {
            iReault = iPivot;
            iLeft = iPivot + 1;
        }
    }

    cout << iReault << '\n';

    return 0;
}