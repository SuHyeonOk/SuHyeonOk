#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; 
    cin >> N;
    cin.ignore();
    
    for (int i = 1; i <= N; i++) 
    {
        string s, temp, ans;
        stack<string> st;
        getline(cin, s);

        for (int k = 0; k < s.length(); k++) 
        {
            if (s[k] == ' ')
            {
                st.push(temp);
                st.push(" ");
                temp.clear();
            }
            else
            {
                temp += s[k];
            }
        }

        st.push(temp);
        while (false == st.empty()) 
        {
            ans += st.top();
            st.pop();
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }

    return 0;
}