#include <iostream>

using namespace std;

int recur(int n, int r, int c) {
    if (n == 1) {
        return 2 * r + c;
    }
    else {
        int ret = 0;
        int divi = (1 << (n - 1));
        if (r >= divi) {
            r -= divi;
            ret += divi * divi * 2;
        }
        if (c >= divi) {
            c -= divi;
            ret += divi * divi;
        }
        return ret + recur(n - 1, r, c);
    }
}

int main(void) {
    int n, r, c;
    cin >> n >> r >> c;

    // 0 <= r, c < 2 ^ n
    
    cout << recur(n, r, c);
}