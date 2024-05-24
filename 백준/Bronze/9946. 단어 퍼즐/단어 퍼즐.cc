#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() 
{
    int as, bs;
    int i = 1;
    
    while (true)
    {
        char a[1001], b[1001];
        cin >> a >> b;
        
        if (!strcmp(a, "END") && !strcmp(b, "END")) { break; }
        as = strlen(a);
        bs = strlen(b);
        if (as != bs)
            cout << "Case " << i++ << ": different" <<'\n';
        else
        {
            sort(a, a + as);
            sort(b, b + bs);
            if(!strcmp(a,b))
                cout << "Case " << i++ << ": same" << '\n';
            else
                cout << "Case " << i++ << ": different" << '\n';
        }
    }
}