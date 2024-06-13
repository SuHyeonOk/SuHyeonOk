#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string one, two, three, four; 
	cin >> one >> two >> three >> four;
    
	string result_1 = one + two; 
	string result_2 = three + four;
    
	long long result = stoll(result_1) + stoll(result_2);
	cout << result;

	return 0; 
}