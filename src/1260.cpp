#include <iostream> 
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

void dfs(vector<int> *adj, vector<int> &vis, int curr) {
    vis[curr] = 1;
    cout << curr << ' ';
    for (auto nxt : adj[curr]) {
        if (!vis[nxt]) {
            vis[nxt] = 1;
            dfs(adj, vis, nxt);
        }
    }
}

void bfs(vector<int> *adj, vector<int> &vis, int curr) {
    deque<int> Q;
    vis[curr] = 1;

    Q.push_back(curr);

    while (!Q.empty()) {
        int v_curr = Q.front();
        cout << v_curr << ' ';
        Q.pop_front();

        for (auto nxt : adj[v_curr]) {
            if (!vis[nxt]) {
                vis[nxt] = 1;
                Q.push_back(nxt);
            }
        }
    }
}

int main(void) {
    int n, m, v;
    cin >> n >> m >> v;
    
    vector<int> adj[1004];
    vector<int> vis(1004);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(adj, vis, v);
    cout << '\n';

    vis = vector<int>(1004, 0);
    bfs(adj, vis, v);
}