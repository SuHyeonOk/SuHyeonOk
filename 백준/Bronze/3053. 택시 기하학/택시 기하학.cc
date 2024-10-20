#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    double R = 0.0;
    cin >> R;

    cout << fixed;
    cout.precision(6);

    // 유클리드 기하학에서의 원의 넓이
    cout << M_PI * R * R << '\n';  // M_PI == π

    // 택시 기하학에서의 원의 넓이
    cout << 2 * R * R << '\n';

    return 0;
}