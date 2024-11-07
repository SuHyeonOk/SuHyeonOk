#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int S = 0, P = 0;
	cin >> S >> P;

	string DNA = "";
	cin >> DNA;

	int arr[100]{ 0 };
	cin >> arr['A'];
	cin >> arr['C'];
	cin >> arr['G'];
	cin >> arr['T'];

	int Start = 0;
	int End = Start + P - 1;

	int copy[100]{ 0 };
	for (int j = Start; j <= End; j++)
	{
		copy[DNA[j]]++;
	}

	int Count = 0;
	while (End < DNA.size()) 
	{
		if (arr['A'] <= copy['A'] && arr['C'] <= copy['C'] &&
			arr['G'] <= copy['G'] && arr['T'] <= copy['T']) 
		{
			++Count;
		}
		copy[DNA[Start++]]--;
		copy[DNA[++End]]++;
	}
	cout << Count;

	return 0;
}