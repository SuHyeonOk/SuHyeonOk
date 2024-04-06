#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map<string, string> m;
    m.insert({ "black", "0"});
    m.insert({ "brown", "1"});
    m.insert({ "red", "2"});
    m.insert({ "orange", "3"});
    m.insert({ "yellow", "4"});
    m.insert({ "green", "5"});
    m.insert({ "blue", "6"});
    m.insert({ "violet", "7"});
    m.insert({ "grey", "8"});
    m.insert({ "white", "9"});

    string Input = "white";
    cin >> Input;
    string Result = m[Input];

    cin >> Input;
    Result += m[Input];

    cin >> Input;
    int Num = stoi(m[Input]);
    for (int i = 0; i < Num; ++i)
    {
        Result += "0";
    }

    cout << stol(Result);

    return 0;
}