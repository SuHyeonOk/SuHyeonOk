#include <bits/stdc++.h>
using namespace std;

int bridge_len;
int lamp_cnt;
int* lamp_position;

void input(){
    cin >> bridge_len >> lamp_cnt;
    lamp_position = new int[lamp_cnt];
    for(int i = 0; i < lamp_cnt; i++) {
        cin >> lamp_position[i];
    }
}

void solution() {
    int result = 1;
    for(int i = 0; i < lamp_cnt; i++) {
        if (i == 0) {
            result = max(result, lamp_position[i]);
        }
        else {
            result = max(result, (lamp_position[i] - lamp_position[i - 1] + 1) / 2);
        }
        if (i == lamp_cnt - 1) {
            result = max(result, bridge_len - lamp_position[i]);
        }
    }
    cout << result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solution();
    delete[] lamp_position;
}