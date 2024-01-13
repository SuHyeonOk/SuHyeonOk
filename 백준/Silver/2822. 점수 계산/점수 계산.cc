#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
	int input_score[8] = { 0, };
	vector<int> score;

	for (int i = 0; i < 8; i++) 
    {
		cin >> input_score[i];
		score.push_back(input_score[i]);
	}

	sort(input_score, input_score + 8, greater<int>());

	int final_score = 0;
	int index[5] = { 0, };

	for (int i = 0; i < 5; i++) 
    {
		final_score += input_score[i]; 
		int index_Q = find(score.begin(), score.end(), input_score[i]) - score.begin();
		index[i] = index_Q + 1;
	}

	cout << final_score << endl;
	sort(index, index + 5);

	for (int i = 0; i < 5; i++) 
    {
		cout << index[i] << " ";
	}

	return 0;
}