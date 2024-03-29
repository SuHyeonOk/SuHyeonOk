#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int Total = 0;
    cin >> Total;

    int Book = 0;
    for (size_t i = 0; i < 9; i++)
    {
        cin >> Book;
        Total -= Book;
    }

    cout << Total;

    return 0;
}