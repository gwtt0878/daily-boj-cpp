#include <iostream>

using namespace std;

int check_bits(int n) {
    int cnt = 0;
    for (int i = 0; i <= 26; i++) {
        if (n & (1 << i)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;

    int answer = 0;
    int cnt = 0;
    // k개 이하로 만들 것.
    // 같은 양 일때만 연산 가능. -> 물병은 2 ^ N
    
    while (check_bits(n) > k) {
        answer += n & (-n);
        n += n & (-n); // 마지막 비트 더하기
    } 

    cout << answer;
}