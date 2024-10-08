#include <iostream>
#include <cstring>
using namespace std;

int fire[2000001];

int main()
{
	int N = 0, C = 0;
	int count = 0;
	int student[100];

	cin >> N >> C;

	for (int i = 0; i < N; ++i) 
    {
		cin >> student[i];
	}

	for (int i = 0; i < N; ++i) 
    {
		for (int j = student[i]; j <= C; j += student[i]) 
        {
			fire[j] = 1;
		}
	}

	for (int i = 0; i <= C; ++i) 
    {
		if (fire[i] == 1) 
        {
			++count;
		}
	}

	cout << count << endl;

	return 0;
}

