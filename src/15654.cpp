#include <iostream> 
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

void print_arr(vector<int> &arr, deque<int> &temp, int cnt, vector<int> &vis) {
    if (cnt == 0) {
        for (auto &elem : temp)
            cout << elem << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (!vis[i]) {
            vis[i] = 1;
            temp.push_back(arr[i]);
            print_arr(arr, temp, cnt - 1, vis);
            vis[i] = 0;
            temp.pop_back();
        }
    }
}

int main(void) {
    int n, m;

    cin >> n >> m;

    vector<int> arr(n), visited(n, 0);
    
    for (auto &elem : arr)
    cin >> elem;

    deque<int> temp;

    sort(arr.begin(), arr.end());

    print_arr(arr, temp, m, visited);
}