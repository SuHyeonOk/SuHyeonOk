#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N = 0;
	string Pattern = "";
	cin >> N >> Pattern;

	int Position = Pattern.find('*');
	string Start = Pattern.substr(0, Position);
	string End = Pattern.substr(Position + 1, Pattern.size());


	string Input = "";
	for (int i = 0; i < N; i++) 
	{
		cin >> Input;

		if (Input.size() < Start.size() + End.size()) // 비교할 문자보다 문자 길이가 짧다면 NE
		{
			cout << "NE" << "\n";
			continue;
		}

		// 비교할 길이 만큼의 문자 Input에서 떼오기
		string InputStart = Input.substr(0, Start.size());
		string InputEnd = Input.substr(Input.size() - End.size(), Input.size());

		if (InputStart == Start && InputEnd == End)
		{
			cout << "DA" << "\n";
		}
		else
		{
			cout << "NE" << "\n";
		}

	}

	return 0;
}