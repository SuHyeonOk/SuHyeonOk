#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int A = 0, B = 0, C = 0;
    cin >> A >> B >> C;

    cout << A + B - C << '\n';

    string Temp = to_string(A) + to_string(B);
    int Result = stoi(Temp) - C;
    cout << Result;

    return 0;
}