#include <iostream>
using namespace std;
 
bool canTake[1001];
int L, N;
int firstCnt = 0, firstAns, secondCnt = 0, secondAns;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> L >> N;
    int left, right, temp;
    for(int idx=1; idx<=N; idx++){
        cin >> left >> right;
        
        // 기대하고 있는 케이크 개수
        if(firstCnt < right - left + 1){
            firstCnt = right - left + 1;
            firstAns = idx;
        }
 
        temp = 0; // 실제 받는 케이크 개수
        for(int i=left; i<=right; i++){
            if(!canTake[i]){
                temp++;
                canTake[i] = true;
            }
        }
        // 기존에 받은 사람보다 더 많이 받는 경우
        if(secondCnt < temp){
            secondCnt = temp;
            secondAns = idx;
        }
    }
 
    cout << firstAns << '\n' << secondAns;
}