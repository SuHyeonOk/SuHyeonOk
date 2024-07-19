#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int gcd(int a, int b) 
{
    return !b ? a : gcd(b, a % b);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T = 0 ;
    cin >> T;
    cin.ignore();
    
    int Max = -1;
    int temp = 0;
    string Line = "";
    string Num = "";
    vector<int> vec;
    
    while (T--) 
    {
        vec.clear();
        Max = -1;

        getline(cin, Line);
        stringstream sstream(Line);
        while (getline(sstream, Num, ' '))
        {
            vec.push_back(stoi(Num));
        }

        for (int i = 0; i < vec.size() - 1; ++i) 
        {
            for (int j = i + 1; j < vec.size(); ++j) 
            {
                temp = gcd(vec[i], vec[j]);
                Max = Max < temp ? temp : Max;
            }
        }
        cout << Max << '\n';
    }

    return 0;
}
