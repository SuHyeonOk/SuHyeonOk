#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> fileNames;
map<string, int> ex;

int main() 
{
    
    int N;
    cin >> N;
    for (int i=0; i<N; i++) 
    {
        string file;
        cin >> file;
        int dot = (int)file.find('.');
        ex[file.substr(dot+1)]++;
    }

    for (map<string, int>::iterator iter = ex.begin(); iter != ex.end(); iter++) 
    {
        cout << iter->first << " " << iter->second << "\n";
    }
    
    return 0;
}