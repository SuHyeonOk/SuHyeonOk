#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    while (cin >> N) {
        if (N == 0) break;

        vector<pair<string, string>> people;
        string name, height;
        string maxHeight = "0.0";

        for (int i = 0; i < N; ++i) {
            cin >> name >> height;

            // 최대 높이를 문자열 비교로 갱신
            if (height > maxHeight) {
                maxHeight = height;
            }

            people.emplace_back(name, height);
        }

        for (const auto& person : people) {
            if (person.second == maxHeight) { // 문자열로 최대값 비교
                cout << person.first << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
