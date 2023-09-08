#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string N{ 0 };
    cin >> N;
    sort(N.rbegin(), N.rend());
    cout << N;

    return 0;
}