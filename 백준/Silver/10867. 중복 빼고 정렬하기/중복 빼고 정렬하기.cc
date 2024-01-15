#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N{ 0 };
    cin >> N;

    int input{ 0 };
    set<int> num;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        num.insert(input);
    }

    for (set<int>::iterator it = num.begin(); it != num.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}