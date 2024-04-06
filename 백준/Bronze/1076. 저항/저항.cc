#include <iostream>
#include <string>
using namespace std;

string Table(string _Input)
{
    if (_Input == "black")
    {
        return "0";
    }
    else if (_Input == "brown")
    {
        return "1";
    }
    else if (_Input == "red")
    {
        return "2";
    }
    else if (_Input == "orange")
    {
        return "3";
    }
    else if (_Input == "yellow")
    {
        return "4";
    }
    else if (_Input == "green")
    {
        return "5";
    }
    else if (_Input == "blue")
    {
        return "6";
    }
    else if (_Input == "violet")
    {
        return "7";
    }
    else if (_Input == "grey")
    {
        return "8";
    }
    else if (_Input == "white")
    {
        return "9";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string Input = "", Result = "";
    
    for (size_t i = 0; i < 2; i++)
    {
        cin >> Input;
        Result += Table(Input);
    }

    cin >> Input;
    int Num = stoi(Table(Input));
    for (int i = 0; i < Num; ++i)
    {
        Result += "0";
    }

    cout << stol(Result);

    return 0;
}