#include <iostream>
#include <deque>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

void dijk(deque<pair<int, int>> * adj, vector<int> & dist, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> PQ;

    dist[start] = 0;
    PQ.push({0, start});

    while (!PQ.empty()) {
        auto [d, curr] = PQ.top();
        PQ.pop();

        for (auto [nd, nxt] : adj[curr]) {
            if (d + nd < dist[nxt]) {
                dist[nxt] = d + nd;
                PQ.push({d + nd, nxt});
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    int n, e;
    cin >> n >> e;

    deque<pair<int, int>> adj[801];
    vector<int> dist1(n+1, 1 << 29);
    vector<int> dist2(n+1, 1 << 29);
    vector<int> dist3(n+1, 1 << 29);

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int v1, v2;
    cin >> v1 >> v2;

    dijk(adj, dist1, 1);
    dijk(adj, dist2, v1);
    dijk(adj, dist3, v2);

    if (dist1[v1] == (1 << 29) || dist2[v2] == (1 << 29) || dist3[n] == (1 << 29))
        cout << -1;
    else {
        // v1 -> v2 or v2 -> v1
        // 고려안해서 WR.
        cout << min(dist1[v1] + dist2[v2] + dist3[n], dist1[v2] + dist2[v2] + dist2[n]);
    }
}