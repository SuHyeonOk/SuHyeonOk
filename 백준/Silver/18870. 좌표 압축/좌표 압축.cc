#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 };
    cin >> N;

    vector<int> vec(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    vector<int> copyVec(vec);
    sort(copyVec.begin(), copyVec.end());
    copyVec.erase(unique(copyVec.begin(), copyVec.end()), copyVec.end());

    for (int i = 0; i < N; i++)
    {
        cout << lower_bound(copyVec.begin(), copyVec.end(), vec[i]) - copyVec.begin() << " ";
    }

    return 0;
}