#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	int N{ 0 }, M{ 0 };
	cin >> N >> M;

	map<string, string> input0;
	map<string, string> input1;
	
	string name{ "" }, temp{ "" };
	for (int i = 1; i <= N; i++)
	{
		cin >> name;

		temp = to_string(i);
		input0.emplace(name, temp);
		input1.emplace(temp, name);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> name;
		auto result = input0.find(name);
		if (input0.end() == result)
		{
			// 못 찾았다면 다른 map에서 찾는다.
			 
			result = input1.find(name);
			cout << result->second << '\n';
		}
		else
		{
			// 찾았으면 바로 출력

			cout << result->second << '\n';
		}
	}

	return 0;
}