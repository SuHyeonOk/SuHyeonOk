#include <iostream>
#include<deque>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t{ 0 };
    cin >> t;

    int n{ 0 };
    string order{ "" }, str{ "" };

    while (t--) 
    {
        deque<int> dq;

        cin >> order;
        cin >> n;
        cin >> str;

        string strTemp{ "" };
        for (int i = 0; i < str.length(); i++) 
        {

            if (isdigit(str[i])) 
            {
                strTemp += str[i];
            }
            else 
            {
                if (false == strTemp.empty()) 
                {
                    dq.push_back(stoi(strTemp));
                    strTemp = "";
                }
            }
        }

        bool reverse{ false }, error{ false };
        for (auto at : order)
        {
            if (at == 'R') 
            {
                if (reverse)
                {
                    reverse = false;
                }
                else
                {
                    reverse = true;
                }
            }
            else 
            {
                if (true == dq.empty()) 
                {
                    cout << "error" << '\n';
                    error = true;
                    break;
                }
                if (reverse)
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
                }
            }
        }

        if (false == error) 
        {
            cout << '[';
        }
        if (reverse && false == dq.empty()) 
        {
            for (auto at = dq.rbegin(); at != dq.rend(); at++) 
            {
                if (at == dq.rend() - 1)
                {
                    cout << *at;
                }
                else
                {
                    cout << *at << ',';
                }
            }
        }
        else if (false == reverse && false == dq.empty()) 
        {
            for (auto at = dq.begin(); at != dq.end(); at++) 
            {
                if (at == dq.end() - 1)
                {
                    cout << *at;
                }
                else
                {
                    cout << *at << ',';
                }
            }
        }
        if (false == error)
        {
            cout << "]\n";
        }
    }
}