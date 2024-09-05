#include <iostream>
#include <set>
using namespace std;

int main() 
{
    int n;
    char game;
    set<string> s;
    
    cin >> n >> game;
    for(int i=0; i<n; i++) {                                                            
        string str;
        cin >> str;
        s.insert(str);
    }
    
        if(game == 'Y') {
        cout << s.size();
    }
    else if(game == 'F') {
        cout << s.size()/2;
    }
    else {
        cout << s.size()/3;
    }
    
    return 0;
}