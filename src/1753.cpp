#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int v, e;
    cin >> v >> e;
    int k; cin >> k;

    vector<pair<int, int>> adj[20001];

    while (e--) {
        int a, b, dist;
        cin >> a >> b >> dist;

        adj[a].push_back({dist, b});
    }

    for (auto elem : adj) {
        sort(elem.begin(), elem.end());
    }

    vector<int> dist(v + 1, 1 << 29);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> PQ;
    PQ.push({0, k});
    dist[k] = 0;

    while (!PQ.empty()) {
        auto [d, curr] = PQ.top();
        PQ.pop();
        for (auto [nd, nxt] : adj[curr]) {
            if (dist[nxt] > d + nd) {
                dist[nxt] = d + nd;
                PQ.push({d + nd, nxt});
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == (1 << 29)) {
            cout << "INF\n";
        } else {
            cout << dist[i] << '\n';
        }
    }
}