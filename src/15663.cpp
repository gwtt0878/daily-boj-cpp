#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

void recur(int n, int cnt, map<int, int> & elements, deque<int> result) {
    if (cnt == 0) {
        for (auto & elem : result)
            cout << elem << ' ';
        cout << '\n';
        return;
    }

    for (auto & [elem, elem_cnt] : elements) {
        if (elem_cnt > 0) {
            result.push_back(elem);
            elem_cnt--;
            recur(n, cnt-1, elements, result);
            elem_cnt++;
            result.pop_back();
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    deque<int> res;
    map<int, int> elements;
    while (n--) {
        int elem;
        cin >> elem;
        if (elements.count(elem) == 0) {
            elements[elem] = 0;
        }
        elements[elem]++;
    }

    recur(n, m, elements, res);
}