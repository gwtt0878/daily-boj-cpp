#include <iostream>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    
    int n, m;
    int presum[1030][1030] = {};    
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;

            presum[i][j] = presum[i][j - 1] + num;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            presum[i][j] += presum[i-1][j];
        }
    }

    // presum[i, j] > (1, 1) ~ (i, j) 합
    
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << presum[x2][y2] 
                - presum[x2][y1 - 1]
                - presum[x1 - 1][y2]
                + presum[x1 - 1][y1 - 1] << '\n';
    }
}