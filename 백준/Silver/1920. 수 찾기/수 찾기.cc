#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n{ 0 };
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int m{ 0 }, target{ 0 };
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> target;
        cout << binary_search(A.begin(), A.end(), target) << '\n';
    }

    return 0;
}